//
// Logitech Gaming LED SDK
//
// Copyright (C) 2011-2014 Logitech. All rights reserved.
// Author: Tiziano Pigliucci
// Email: devtechsupport@logitech.com

#pragma once

#define LOGI_LED_BITMAP_WIDTH 21
#define LOGI_LED_BITMAP_HEIGHT 6
#define LOGI_LED_BITMAP_BYTES_PER_KEY 4

#define LOGI_LED_BITMAP_SIZE (LOGI_LED_BITMAP_WIDTH*LOGI_LED_BITMAP_HEIGHT*LOGI_LED_BITMAP_BYTES_PER_KEY)

#define LOGI_LED_DURATION_INFINITE 0

#define LOGI_DEVICETYPE_MONOCHROME_ORD  0
#define LOGI_DEVICETYPE_RGB_ORD         1
#define LOGI_DEVICETYPE_PERKEY_RGB_ORD  2

#define LOGI_DEVICETYPE_MONOCHROME  (1 << LOGI_DEVICETYPE_MONOCHROME_ORD)
#define LOGI_DEVICETYPE_RGB         (1 << LOGI_DEVICETYPE_RGB_ORD)
#define LOGI_DEVICETYPE_PERKEY_RGB  (1 << LOGI_DEVICETYPE_PERKEY_RGB_ORD)

#define LOGI_DEVICETYPE_ALL (LOGI_DEVICETYPE_MONOCHROME | LOGI_DEVICETYPE_RGB | LOGI_DEVICETYPE_PERKEY_RGB)


bool LogiLedInit();

bool LogiLedGetSdkVersion(int *majorNum, int *minorNum, int *buildNum);
bool LogiLedGetConfigOptionNumber(const wchar_t *configPath, double *defaultValue);
bool LogiLedGetConfigOptionBool(const wchar_t *configPath, bool *defaultValue);
bool LogiLedGetConfigOptionColor(const wchar_t *configPath, int *defaultRed, int *defaultGreen, int *defaultBlue);
bool LogiLedGetConfigOptionRect(const wchar_t *configPath, int *defaultX, int *defaultY, int *defaultWidth, int *defaultHeight);
bool LogiLedGetConfigOptionString(const wchar_t *configPath, wchar_t *defaultValue, int bufferSize);
bool LogiLedGetConfigOptionKeyInput(const wchar_t *configPath, wchar_t *defaultValue, int bufferSize);
bool LogiLedGetConfigOptionSelect(const wchar_t *configPath, wchar_t *defaultValue, int *valueSize, const wchar_t *values, int bufferSize);
bool LogiLedGetConfigOptionRange(const wchar_t *configPath, int *defaultValue, int min, int max);
bool LogiLedSetConfigOptionLabel(const wchar_t *configPath, wchar_t *label);

//Generic functions => Apply to any device type.
bool LogiLedSetTargetDevice(int targetDevice);
bool LogiLedSaveCurrentLighting();
bool LogiLedSetLighting(int redPercentage, int greenPercentage, int bluePercentage);
bool LogiLedRestoreLighting();
bool LogiLedFlashLighting(int redPercentage, int greenPercentage, int bluePercentage, int milliSecondsDuration, int milliSecondsInterval);
bool LogiLedPulseLighting(int redPercentage, int greenPercentage, int bluePercentage, int milliSecondsDuration, int milliSecondsInterval);
bool LogiLedStopEffects();

void LogiLedShutdown();

