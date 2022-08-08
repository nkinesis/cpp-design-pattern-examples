#pragma once
#include <iostream>

// Pattern studies: command

class Command {
public:
	virtual ~Command() {
	};
	virtual void execute() const = 0;
};

class Spaceship {
private:
	std::string spaceshipName;
public:
	Spaceship(std::string name) {
		spaceshipName = name;
	}
	void move(int direction) {
		if (direction == 0) {
			std::cout << spaceshipName << " moves left!\n";
		}
		else {
			std::cout << spaceshipName << " moves right!\n";
		}
	}
	void shoot() {
		std::cout << spaceshipName << " shoots!\n";
	}
};

class MoveCommand : public Command {
private:
	Spaceship* receiver_;
	int direction = 0;
public:
	MoveCommand(Spaceship* obj, int direction) {
		direction = direction;
		receiver_ = obj;
	}
	void execute() const override {
		receiver_->move(direction);
	}
};

class ShootCommand : public Command {
private:
	Spaceship* receiver_;
public:
	ShootCommand(Spaceship* obj) {
		receiver_ = obj;
	}
	void execute() const override {
		receiver_->shoot();
	}
};

class Invoker {
private:
	Command* on_start_;
	Command* on_finish_;
public:
	~Invoker() {
		delete on_start_;
		delete on_finish_;
	}

	void setOnStart(Command* command) {
		this->on_start_ = command;
	}
	void setOnFinish(Command* command) {
		this->on_finish_ = command;
	}

	void execute() {
		std::cout << "Before start\n";
		if (this->on_start_) {
			this->on_start_->execute();
			std::cout << "Started\n";
		}
		std::cout << "Running\n";
		std::cout << "Before finish\n";
		if (this->on_finish_) {
			this->on_finish_->execute();
			std::cout << "Finished\n";
		}
	}
};