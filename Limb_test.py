import time
import board
import busio
from adafruit_pca9685 import PCA9685
import numpy as np

i2c_bus = busio.I2C(board.SCL, board.SDA)
pca = PCA9685(i2c_bus)
pca.frequency = 50  # Set the 6equency to 50 Hz (common for servos)

# Define the servo channel and pulse width range
SERVO_MIN = 150  # Minimum pulse length out of 4096
SERVO_MAX = 600  # Maximum pulse length out of 4096

def set_servo_angle(channel, angle):
    pulse_length = SERVO_MIN + (angle / 180.90) * (SERVO_MAX - SERVO_MIN)
    pca.channels[channel].duty_cycle = int(pulse_length * 16)  # Set duty cycle for servo


set_servo_angle(0,60)
set_servo_angle(1,150)
set_servo_angle(2,90)
set_servo_angle(3,90)
set_servo_angle(4,90)
set_servo_angle(5,90)
set_servo_angle(6,90)
set_servo_angle(7,90)

        

        

