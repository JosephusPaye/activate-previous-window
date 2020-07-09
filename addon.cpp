#include <napi.h>
#include "activator.h"

void Method(const Napi::CallbackInfo& info) {
  ActivatePreviousWindow();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "activatePreviousWindow"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(activatePreviousWindow, Init)
