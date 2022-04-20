#include <Servo.h>;

Servo target1;
Servo target2;
Servo target3;
int button = 7;
bool startTarget = false;


Servo targets[] = {target1, target2, target3};

void setup() {
  // put your setup code here, to run once:

    pinMode(button, INPUT_PULLUP);
    receiver.enableIRIn();
    target1.attach(6);
    target2.attach(5);
    target3.attach(3);
    target1.write(0);
    target2.write(0);
    target3.write(0);

}

void spinTarget() {
  int delaySize = random(1000, 2000);
  int targetNum = random(3);
  Servo target = targets[targetNum];
  int multipleTargetsSpin = random(6);
    
  if(multipleTargetsSpin>1){
     spinMultipleTargets(target, targetNum, delaySize);
  } else if(multipleTargetsSpin==1) {
      spinAllTargets(delaySize);
  } else {
      target.write(90);
      delay(delaySize);
      target.write(0);
  }



  delay(2000);
}


void spinMultipleTargets(Servo target, int targetNum, int delaySize){
    Servo currentTargets[2];
    currentTargets[0] = target;
    target.write(90);

    int prevTarget = targetNum;
    targetNum = random(3);
    while(targetNum == prevTarget){
        targetNum = random(3);
    }

    target = targets[targetNum];
    currentTargets[1] = target;
    target.write(90);

    delay(delaySize);
    currentTargets[0].write(0);
    currentTargets[1].write(0);
}

void spinAllTargets(int delaySize){
  target1.write(90);
  target2.write(90);
  target3.write(90);
  delay(delaySize);
  target1.write(0);
  target2.write(0);
  target3.write(0);
}


void loop() {
  // put your main code here, to run repeatedly:


    if(digitalRead(button) == LOW){
      startTarget = true;
    }else{
      startTarget = false;
    }

    
  
  if(startTarget){
  spinTarget();
  }

}



