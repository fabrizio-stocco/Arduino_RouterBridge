import time
from arduino.app_utils import *
from datetime import datetime


def log(msg):
    with open("./log.log", "a") as f:
        f.write(str(f"{datetime.now():%m/%d/%y %H:%M:%S} {msg}") + "\n")

def main():
    log("CALL ECHO: GREETING")
    res = Bridge.call("echo", "GREETING")
    log(f"RECV ECHO: {res}")
    time.sleep(1)

time.sleep(5)

if __name__ == "__main__":
    while True:
        main()