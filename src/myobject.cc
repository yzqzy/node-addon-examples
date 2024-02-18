#include "myobject.h"

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "MyObject",
                                    {
                                        InstanceMethod("value", &MyObject::GetValue),
                                        InstanceMethod("plusOne", &MyObject::PlusOne),
                                        InstanceMethod("multiply", &MyObject::Multiply),
                                    });

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData<Napi::FunctionReference>(constructor);

  exports.Set("MyObject", func);
  return exports;
}

MyObject::MyObject(const Napi::CallbackInfo &info) : Napi::ObjectWrap<MyObject>(info) {
  Napi::Env env = info.Env();

  int length = info.Length();

  if (length <= 0 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "The first argument must be a number").ThrowAsJavaScriptException();
    return;
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->value_ = value.DoubleValue();
}

Napi::Value MyObject::GetValue(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  double num = this->value_;
  return Napi::Number::New(env, num);
}

Napi::Value MyObject::PlusOne(const Napi::CallbackInfo &info) {
  this->value_ = this->value_ + 1;
  return MyObject::GetValue(info);
}

Napi::Value MyObject::Multiply(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  Napi::Number multiple;

  if (info.Length() <= 0 || !info[0].IsNumber()) {
    multiple = Napi::Number::New(env, 1);
  } else {
    multiple = info[0].As<Napi::Number>();
  }

  Napi::Object obj = env.GetInstanceData<Napi::FunctionReference>()->New(
      {Napi::Number::New(env, this->value_ * multiple.DoubleValue())});

  return obj;
}
