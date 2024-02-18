#include <napi.h>
#include "myobject.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return MyObject::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
