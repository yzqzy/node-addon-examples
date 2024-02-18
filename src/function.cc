#include <napi.h>

Napi::String MyFunction(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "Hello World!");
}

Napi::Function CreateFunction(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::Function fn = Napi::Function::New(env, MyFunction, "thenFunction");
  return fn;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, CreateFunction, "createFunction");
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
