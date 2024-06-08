class Car{
    public:
        Car();
        void accelerate(double speed);
        private:
        float speed;
}

Car::Car(){
    speed = 0;
}

void Car::accelerate(double speed){
    speed += 0.5;
}

int main(){
    Car car1;
    car1.accelerate(10);

    Car car2;
    car2.accelerate(20);

    /* code */
}
