#include <Servo.h>

Servo front_r_servo;
Servo front_l_servo;
Servo back_r_servo;
Servo back_l_servo;

#define front_r_servo_pin 8
#define front_l_servo_pin 9
#define back_r_servo_pin 10
#define back_l_servo_pin 11

#define min_front_r_servo 1000
#define trim_front_r_servo 1500
#define max_front_r_servo 2000

#define min_front_l_servo 1000
#define trim_front_l_servo 1500
#define max_front_l_servo 2000

#define min_back_r_servo 1000
#define trim_back_r_servo 1500
#define max_back_r_servo 2000

#define min_back_l_servo 1000
#define trim_back_l_servo 1500
#define max_back_l_servo 2000

#define move_front_delay 500
#define move_back_delay 500
#define move_right_delay 500
#define move_left_delay 500

void setup_servos(){
  front_r_servo.attach(front_r_servo_pin);
  front_l_servo.attach(front_l_servo_pin);
  back_r_servo.attach(back_r_servo_pin);
  back_l_servo.attach(back_l_servo_pin);
}

void test_move(){
  delay(3000);
  front_r_servo.writeMicroseconds(max_front_r_servo);
  front_l_servo.writeMicroseconds(max_front_l_servo);
  back_r_servo.writeMicroseconds(max_back_r_servo);
  back_l_servo.writeMicroseconds(max_back_l_servo);
  delay(1000);
  front_r_servo.writeMicroseconds(min_front_r_servo);
  front_l_servo.writeMicroseconds(min_front_l_servo);
  back_r_servo.writeMicroseconds(min_back_r_servo);
  back_l_servo.writeMicroseconds(min_back_l_servo);
  delay(1000);
  front_r_servo.writeMicroseconds(trim_front_r_servo);
  front_l_servo.writeMicroseconds(trim_front_l_servo);
  back_r_servo.writeMicroseconds(trim_back_r_servo);
  back_l_servo.writeMicroseconds(trim_back_l_servo);
  delay(1000);  
}

void move_foot_front(bool left, int signal){
  if (left){
    front_l_servo.writeMicroseconds(signal);
  }

  else{
    front_r_servo.writeMicroseconds(signal);
  }
}

void move_foot_back(bool left, int signal){
  if (left){
    back_l_servo.writeMicroseconds(signal);
  }

  else{
    back_r_servo.writeMicroseconds(signal);
  }
}

void move_front(){
    move_foot_front(true, max_front_l_servo); // move left front
    delay(move_front_delay);
    move_foot_front(false, max_front_r_servo); // move right front
    delay(move_front_delay);

    move_foot_back(true, max_back_l_servo); // move back left
    delay(move_front_delay);

    // trim front feet
    move_foot_front(true, trim_front_l_servo); // move left front
    delay(move_front_delay);
    move_foot_front(false, trim_front_r_servo); // move right front
    delay(move_front_delay);

    move_foot_back(false, max_back_r_servo); // move back left
    delay(move_front_delay);

    // trim back feet
    move_foot_front(true, trim_back_l_servo); // move left front
    delay(move_front_delay);
    move_foot_front(false, trim_back_r_servo); // move right front
    delay(move_front_delay);
  
}

void move_left(){
  move_foot_front(true, max_front_l_servo);
  delay(move_left_delay);
  move_foot_front(false, trim_front_r_servo);
  delay(move_left_delay);

  move_foot_back(true, max_back_l_servo);
  delay(move_left_delay);
  move_foot_back(false, trim_back_r_servo);
  delay(move_left_delay);

  move_foot_front(true, trim_front_l_servo);
  delay(move_left_delay);
  move_foot_front(false, trim_front_r_servo);
  delay(move_left_delay);

  move_foot_back(true, trim_back_l_servo);
  delay(move_left_delay);
  move_foot_back(false, trim_back_r_servo);
  delay(move_left_delay);
}

void move_right(){
  move_foot_front(false, max_front_r_servo);
  delay(move_right_delay);
  move_foot_front(true, trim_front_l_servo);
  delay(move_right_delay);

  move_foot_back(false, max_back_r_servo);
  delay(move_right_delay);
  move_foot_back(true, trim_back_l_servo);
  delay(move_right_delay);

  move_foot_front(false, trim_front_r_servo);
  delay(move_right_delay);
  move_foot_front(true, trim_front_l_servo);
  delay(move_right_delay);

  move_foot_back(false, trim_back_r_servo);
  delay(move_right_delay);
  move_foot_back(true, trim_back_l_servo);
  delay(move_right_delay);
}

void move_back(){
  move_foot_front(true, min_front_l_servo);
  delay(move_back_delay);
  move_foot_front(false, min_front_r_servo);
  delay(move_back_delay);

  move_foot_back(true, min_back_l_servo);
  delay(move_back_delay);

  move_foot_front(true, trim_front_l_servo);
  delay(move_back_delay);
  move_foot_front(false, trim_front_r_servo);
  delay(move_back_delay);

  move_foot_back(false, min_back_r_servo);
  delay(move_back_delay);

  move_foot_back(true, trim_back_l_servo);
  delay(move_back_delay);
  move_foot_back(false, trim_back_r_servo);
  delay(move_back_delay);
}

void setup() {
  // put your setup code here, to run once:
  setup_servos();
  test_move();
}

void loop() {
  // put your main code here, to run repeatedly:

}
