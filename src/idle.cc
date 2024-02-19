#include <napi.h>
#include <uv.h>

namespace __idle__ {

unsigned int idle_times = 0;
uv_idle_t *idle = nullptr;

void test_idle(uv_idle_t *handle) {
  idle_times--;

  printf("Idle callback called. %u times left.\n", idle_times);

  if (idle_times == 0) {
    idle = nullptr;
    uv_idle_stop(handle);
    delete handle;
  }
}

Napi::Value Idle(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (idle != 0) {
    Napi::TypeError::New(env, "Idle already started").ThrowAsJavaScriptException();
    return env.Null();
  }

  idle_times = info[0].As<Napi::Number>().Uint32Value();

  idle = new uv_idle_t();
  uv_idle_init(uv_default_loop(), idle);

  uv_idle_start(idle, test_idle);

  return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "startIdle"), Napi::Function::New(env, Idle));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

} // namespace __idle__
