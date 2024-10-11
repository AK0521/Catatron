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


set_servo_angle(0,90)
set_servo_angle(1,90)
set_servo_angle(2,90)
set_servo_angle(3,90)
set_servo_angle(4,90)
set_servo_angle(5,90)
set_servo_angle(6,90)
set_servo_angle(7,90)


curr_angle=[90,90,90,90,90,90,90,90]


def resting_posture():
   
    
    for i in range(31):
        set_servo_angle(0,curr_angle[0]+i)
        set_servo_angle(1,curr_angle[1]-1.5*i)
        set_servo_angle(2,curr_angle[2]-i)
        set_servo_angle(3,curr_angle[3]+1.5*i)
        set_servo_angle(4,curr_angle[4]+i)
        set_servo_angle(5,curr_angle[5]-1.5*i)
        set_servo_angle(6,curr_angle[6]-i)
        set_servo_angle(7,curr_angle[7]+1.5*i)
        time.sleep(0.05)
    
    curr_angle[0]=120
    curr_angle[1]=45
    curr_angle[2]=60
    curr_angle[3]=135
    curr_angle[4]=120
    curr_angle[5]=45
    curr_angle[6]=60
    curr_angle[7]=135
    

def walking_stance():
    ratio1=7/6
    ratio2=1/3
    for i in range(31):
        set_servo_angle(0,curr_angle[0]-i)
        set_servo_angle(1,curr_angle[1]+ratio1*i)
        set_servo_angle(2,curr_angle[2])
        set_servo_angle(3,curr_angle[3]-ratio2*i)
        set_servo_angle(4,curr_angle[4])
        set_servo_angle(5,curr_angle[5]+ratio2*i)
        set_servo_angle(6,curr_angle[6]+i)
        set_servo_angle(7,curr_angle[7]-ratio1*i)
        time.sleep(0.02)

    time.sleep(1)
    
# set_servo_angle(0,120-30)
# set_servo_angle(1,50+30)
# set_servo_angle(2,30+30)
# set_servo_angle(3,155-30)
# set_servo_angle(4,150-30)
# set_servo_angle(5,25+30)
# set_servo_angle(6,60+30)
# set_servo_angle(7,130-30)
    curr_angle[0]=curr_angle[0]-30 #90
    curr_angle[1]=curr_angle[1]+35 #80
    curr_angle[2]=curr_angle[2]  #60
    curr_angle[3]=curr_angle[3]-10 # 125
    curr_angle[4]=curr_angle[4] #120
    curr_angle[5]=curr_angle[5]+10 #55
    curr_angle[6]=curr_angle[6]+30 #90
    curr_angle[7]=curr_angle[7]-35 #100
    

def walk():
    ratio1=5/4
    for i in  range(21):
        set_servo_angle(0,curr_angle[0]+i)
        set_servo_angle(1,curr_angle[1]-ratio1*i)
        set_servo_angle(2,curr_angle[2]+i)
        set_servo_angle(3,curr_angle[3]-ratio1*i)
        set_servo_angle(4,curr_angle[4]-i)
        set_servo_angle(5,curr_angle[5]+ratio1*i)
        set_servo_angle(6,curr_angle[6]-i)
        set_servo_angle(7,curr_angle[7]+ratio1*i)
        time.sleep(0.01)
    curr_angle[0]=curr_angle[0]+20 #90
    curr_angle[1]=curr_angle[1]-25 #80
    curr_angle[2]=curr_angle[2]+20  #60
    curr_angle[3]=curr_angle[3]-25 # 125
    curr_angle[4]=curr_angle[4]-20 #120
    curr_angle[5]=curr_angle[5]+25 #55
    curr_angle[6]=curr_angle[6]-20 #90
    curr_angle[7]=curr_angle[7]+25 #100
    
    for i in  range(21):
        set_servo_angle(0,curr_angle[0]-i)
        set_servo_angle(1,curr_angle[1]+ratio1*i)
        set_servo_angle(2,curr_angle[2]-i)
        set_servo_angle(3,curr_angle[3]+ratio1*i)
        set_servo_angle(4,curr_angle[4]+i)
        set_servo_angle(5,curr_angle[5]-ratio1*i)
        set_servo_angle(6,curr_angle[6]+i)
        set_servo_angle(7,curr_angle[7]-ratio1*i)
        time.sleep(0.01)
    curr_angle[0]=curr_angle[0]-20 #90
    curr_angle[1]=curr_angle[1]+25 #80
    curr_angle[2]=curr_angle[2]-20  #60
    curr_angle[3]=curr_angle[3]+25 # 125
    curr_angle[4]=curr_angle[4]+20 #120
    curr_angle[5]=curr_angle[5]-25 #55
    curr_angle[6]=curr_angle[6]+20 #90
    curr_angle[7]=curr_angle[7]-25 #100


def forward_resting_posture():
    for i in range(31):
        set_servo_angle(0,curr_angle[0]-i)
        set_servo_angle(1,curr_angle[1]+2*i)
        set_servo_angle(2,curr_angle[2]+i)
        set_servo_angle(3,curr_angle[3]-2*i)
        set_servo_angle(4,curr_angle[4]-i)
        set_servo_angle(5,curr_angle[5]+2*i)
        set_servo_angle(6,curr_angle[6]+i)
        set_servo_angle(7,curr_angle[7]-2*i)
        time.sleep(0.05)
    
    curr_angle[0]=60
    curr_angle[1]=150
    curr_angle[2]=120
    curr_angle[3]=30
    curr_angle[4]=60
    curr_angle[5]=150
    curr_angle[6]=120
    curr_angle[7]=30



def forward_walking_stance():
    ratio1=7/6
    ratio2=1/3
    for i in range(31):
        set_servo_angle(0,curr_angle[0]+i)
        set_servo_angle(1,curr_angle[1]-ratio1*i)
        set_servo_angle(2,curr_angle[2])
        set_servo_angle(3,curr_angle[3]+ratio2*i)
        set_servo_angle(4,curr_angle[4])
        set_servo_angle(5,curr_angle[5]-ratio2*i)
        set_servo_angle(6,curr_angle[6]-i)
        set_servo_angle(7,curr_angle[7]+ratio1*i)
        time.sleep(0.02)

    time.sleep(1)
    
# set_servo_angle(0,120-30)
# set_servo_angle(1,50+30)
# set_servo_angle(2,30+30)
# set_servo_angle(3,155-30)
# set_servo_angle(4,150-30)
# set_servo_angle(5,25+30)
# set_servo_angle(6,60+30)
# set_servo_angle(7,130-30)
    curr_angle[0]=curr_angle[0]+30 #90
    curr_angle[1]=curr_angle[1]-35 #80
    curr_angle[2]=curr_angle[2]  #60
    curr_angle[3]=curr_angle[3]+10 # 125
    curr_angle[4]=curr_angle[4] #120
    curr_angle[5]=curr_angle[5]-10 #55
    curr_angle[6]=curr_angle[6]-30 #90
    curr_angle[7]=curr_angle[7]+35 #100



def forward_walk():
    ratio1=5/4
    for i in  range(21):
        set_servo_angle(0,curr_angle[0]-i)
        set_servo_angle(1,curr_angle[1]+ratio1*i)
        set_servo_angle(2,curr_angle[2]-i)
        set_servo_angle(3,curr_angle[3]+ratio1*i)
        set_servo_angle(4,curr_angle[4]+i)
        set_servo_angle(5,curr_angle[5]-ratio1*i)
        set_servo_angle(6,curr_angle[6]+i)
        set_servo_angle(7,curr_angle[7]-ratio1*i)
        time.sleep(0.02)
    curr_angle[0]=curr_angle[0]-20 #90
    curr_angle[1]=curr_angle[1]+25 #80
    curr_angle[2]=curr_angle[2]-20  #60
    curr_angle[3]=curr_angle[3]+25 # 125
    curr_angle[4]=curr_angle[4]+20 #120
    curr_angle[5]=curr_angle[5]-25 #55
    curr_angle[6]=curr_angle[6]+20 #90
    curr_angle[7]=curr_angle[7]-25 #100
    
    for i in  range(21):
        set_servo_angle(0,curr_angle[0]+i)
        set_servo_angle(1,curr_angle[1]-ratio1*i)
        set_servo_angle(2,curr_angle[2]+i)
        set_servo_angle(3,curr_angle[3]-ratio1*i)
        set_servo_angle(4,curr_angle[4]-i)
        set_servo_angle(5,curr_angle[5]+ratio1*i)
        set_servo_angle(6,curr_angle[6]-i)
        set_servo_angle(7,curr_angle[7]+ratio1*i)
        time.sleep(0.02)
    curr_angle[0]=curr_angle[0]+20 #90
    curr_angle[1]=curr_angle[1]-25 #80
    curr_angle[2]=curr_angle[2]+20  #60
    curr_angle[3]=curr_angle[3]-25 # 125
    curr_angle[4]=curr_angle[4]-20 #120
    curr_angle[5]=curr_angle[5]+25 #55
    curr_angle[6]=curr_angle[6]-20 #90
    curr_angle[7]=curr_angle[7]+25 #100



   


       

 # set_servo_angle(0,150-30)
# set_servo_angle(1,25+30)
# set_servo_angle(2,60+30)
# set_servo_angle(3,130-30)
# set_servo_angle(4,120-30)
# set_servo_angle(5,50+30)
# set_servo_angle(6,30+30)
# set_servo_angle(7,155-30)
        
    


try:
    # resting_posture()
    # time.sleep(1)
    # walking_stance()
    # while True:
    #     walk()

    forward_resting_posture()
    time.sleep(1)
    forward_walking_stance()
    while True:
        forward_walk()
     
except KeyboardInterrupt:
    # Turn off a1l servos on exit
    set_servo_angle(0,90)
    set_servo_angle(1,90)
    set_servo_angle(2,90)
    set_servo_angle(3,90)
    set_servo_angle(4,90)
    set_servo_angle(5,90)
    set_servo_angle(6,90)
    set_servo_angle(7,90)

    time.sleep(0.5)

    for channel in range(8):
        pca.channels[channel].duty_cycle = 0
    print("Program stopped")
