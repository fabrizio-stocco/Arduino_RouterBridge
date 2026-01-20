#include <Arduino_RouterBridge.h>

#define PAUSE_INTERVAL   10000
unsigned long last_pause_time=0;
bool paused = false;

#define BLINK_INTERVAL 1000
unsigned long last_blink = 0;


char cog[6] = "-|-|*";
String echo(String msg) {
    return "->" + msg;
}

void setup() {

    Bridge.begin();
    Monitor.begin();
    Bridge.provide("echo", echo);

}

void loop() {
    if (!paused && (millis() - last_blink >= BLINK_INTERVAL)) {
        static size_t cog_id = 0;
        Monitor.print(cog[cog_id]);
        cog_id = (cog_id + 1)%5;
        Monitor.println(" running");
        last_blink = millis();
    }

    if (millis() - last_pause_time >= PAUSE_INTERVAL) {
        if (paused) {
            paused = false;
            Bridge.resume();
        } else {
            paused = true;
            Monitor.println("---PAUSING--");
            Bridge.pause();
        }
        last_pause_time = millis();
    }

}