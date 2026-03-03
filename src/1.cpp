#include "1.h"
#include "Arduino.h"

void begin() {
    Serial.begin(115200);
}
void println(const char* value) {
    Serial.println(value);
}
void println(int value) {
    Serial.println(value);
}
void println() {
    Serial.println();
}
void print(const char* value) {
    Serial.print(value);
}
void print(int value) {
    Serial.print(value);
}
