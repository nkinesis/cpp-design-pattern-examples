#pragma once

// Pattern studies: abstract factory

class Car {
private:
	bool isLuxury = false;

public:
	Car(bool lux) {
		isLuxury = lux;
	}
	bool getLuxury() {
		return isLuxury;
	}
};

class SUV {
private:
	bool isLuxury = false;

public:
	SUV(bool lux) {
		isLuxury = lux;
	}
	bool getLuxury() {
		return isLuxury;
	}
};

class CarFactory {
public:
	Car* getRegularCar() {
		return new Car(false);
	}

	Car* getLuxuryCar() {
		return new Car(true);
	}
};

class SUVFactory {
public:
	SUV* getRegularSUV() {
		return new SUV(false);
	}

	SUV* getLuxurySUV() {
		return new SUV(true);
	}
};

class VehicleFactory {
	virtual Car* getCar() const = 0;
	virtual SUV* getSUV() const = 0;
};

class LuxuryVehicleFactory : VehicleFactory {
public:	
	Car* getCar() const override {
		return new Car(true);
	}
	SUV* getSUV() const override {
		return new SUV(true);
	}
};

class RegularVehicleFactory : VehicleFactory {
public:
	Car* getCar() const override {
		return new Car(false);
	}
	SUV* getSUV() const override {
		return new SUV(false);
	}
};