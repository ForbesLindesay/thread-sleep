#include <nan.h>
#include <chrono>
#include <thread>
#include "./sync.h"

using v8::Number;

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(SleepSync) {
  NanScope();

  // expect a number as the first argument
  int x = args[0]->Uint32Value();

  std::this_thread::sleep_for(std::chrono::milliseconds(x));

  NanReturnValue(NanNew<Number>(x));
}
