#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Engine
{

};

class Entity
{
public:
	Entity()
		: x_(0), y_(0)
	{}

	virtual ~Entity() {}
	virtual void update() = 0;
	virtual void render(SDL_Renderer*) = 0;

	double x() const { return x_; }
	double y() const { return y_; }

	void setX(double x) { x_ = x; }
	void setY(double y) { y_ = y; }

private:
	double x_;
	double y_;
};

class SDL_Init_
{
public:
	SDL_Init_(int, int);
	~SDL_Init_();

	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
};


