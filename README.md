# Wireless Multi-Device Communication using ThingSpeak

**Type:** Wokwi simulation (not physical hardware)

## What It Does
A three-device IoT system where devices communicate indirectly through the ThingSpeak cloud platform rather than directly with each other:

- **Publisher (ESP32):** Connects to WiFi and sends alternating ON/OFF state data to a ThingSpeak channel every 15 seconds.
- **Subscriber 1 (ESP32):** Connects to WiFi, polls the ThingSpeak channel, reads the latest value, and displays it via Serial
- **Subscriber 2 (Raspberry Pi Pico W):** Connects to WiFi, polls the same ThingSpeak channel, and controls an LED based on the received value (ON when value = 1, OFF when value = 0)

All three devices communicate asynchronously through the cloud, rather than device-to-device — a common real-world IoT pattern.

## Live Simulations
- [Publisher (ESP32)](https://wokwi.com/projects/461941087230729217)
- [Subscriber 1 (ESP32)](https://wokwi.com/projects/461942709269013505)
- [Subscriber 2 (Raspberry Pi Pico W)](https://wokwi.com/projects/462018856162220033)

## ThingSpeak Channel
[Live channel — "IoT Control"](https://thingspeak.mathworks.com/channels/3351986)

Field 1 tracks switch status (0/1) over time, visualized as a live graph.

## Code Origin
The core WiFi/HTTP request logic was generated with AI assistance , then understood and modified to fit this specific multi-device publish/subscribe setup.

## What I Learned
- How to connect ESP32 and Raspberry Pi Pico W to WiFi in a simulated environment
- How to send data to a ThingSpeak channel using raw HTTP GET requests (ESP32) and the `urequests` library (MicroPython/Pico)
- How to read/parse data back from a ThingSpeak channel on separate devices
- The publish/subscribe pattern for IoT — devices don't talk directly to each other, they communicate through a shared cloud data source
- Working across two different languages/platforms for the same task: C++ (Arduino-style) for ESP32, MicroPython for the Pico W
