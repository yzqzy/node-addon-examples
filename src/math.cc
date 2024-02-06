#include <napi.h>

Napi::Value Add(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  int a = info[0].As<Napi::Number>();
  int b = info[1].As<Napi::Number>();

  return Napi::Number::New(env, a + b);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
