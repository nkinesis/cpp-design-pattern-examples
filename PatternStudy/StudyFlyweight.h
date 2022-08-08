#pragma once
#include <string>

// Pattern studies: flyweight

class FlyweightMeteor {
private:
	long assetCode = 4324;
	std::string texture;
	std::string model3d;
	std::string particles;
public:
	// imagine we would read this from an assets database
	// every time the class is instantiated, it hits the database
	FlyweightMeteor() {
		texture = "meteor.tex";
		model3d = "meteor01.model";
		particles = "partMeteor.p";
		std::cout << "The asset database was queried now! \n";
	}
};

class FlyweightMeteorFactory {
private:
	FlyweightMeteor* flyweight_ = nullptr;
public:
	FlyweightMeteor* getFlyweight() {
		if (flyweight_ == nullptr) {
			flyweight_ = new FlyweightMeteor();
		}
		return flyweight_;
	}
};

class Meteor {
private:
	unsigned int forwardSpeed = 0;
	float spinSpeed = 0;
	bool spinClockwise = false;
	FlyweightMeteor* objFw;
public:
	Meteor(unsigned int speed, bool spinClockwise, FlyweightMeteor* flyweight) {
		forwardSpeed = (speed > 0) ? speed : 1;
		spinSpeed = (speed > 0 ? speed : 1) / 1.48;
		spinClockwise = spinClockwise;
		objFw = flyweight;
	}
	unsigned int getSpeed() {
		return forwardSpeed;
	}
};