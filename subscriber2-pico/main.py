import network
import urequests
import time
from machine import Pin

ssid = "Wokwi-GUEST"
password = ""

channel_id = "3351986"

led = Pin(15, Pin.OUT)

# Connect to WiFi
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(ssid, password)

print("Connecting to WiFi...")
while not wifi.isconnected():
    time.sleep(0.5)

print("Connected!")

while True:
    try:
        url = "http://api.thingspeak.com/channels/" + channel_id + "/fields/1/last.txt"
        
        response = urequests.get(url)
        data = response.text.strip()
        response.close()

        print("Received:", data)

        if data == "1":
            led.value(1)   # LED ON
        else:
            led.value(0)   # LED OFF

    except:
        print("Error fetching data")


    time.sleep(5)
