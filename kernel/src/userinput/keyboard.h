#pragma once
#include <stdint.h>
#include "kbScancodeTranslation.h"
#include "../BasicRenderer.h"
#include "../cstr.h"

void HandleKeyboard(uint8_t scancode);
char inputBuffer[1024];
int currentInput = 0;