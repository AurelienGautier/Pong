#pragma once

constexpr unsigned short SCREEN_WIDTH = 800;
constexpr unsigned short SCREEN_HEIGHT = 600;

constexpr char BALL_SIZE = 20;

constexpr char RACKET_WIDTH = 20;
constexpr char RACKET_HEIGHT = 100;

constexpr unsigned short LEFT_RACKET_X = 5;
constexpr unsigned short RIGHT_RACKET_X = SCREEN_WIDTH - RACKET_WIDTH - 5;

constexpr char LINE_WIDTH = 10;

struct Position
{
	float x;
	float y;
};