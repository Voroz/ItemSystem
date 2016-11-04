#include "BoundingRect.h"



BoundingRect::BoundingRect(){
	_position = sf::Vector2f(0, 0);
	_center = sf::Vector2f(0, 0);
	_width = 0;
	_height = 0;
}
BoundingRect::~BoundingRect(){

}

sf::Vector2f BoundingRect::pos() {
	return _position;
}
sf::Vector2f BoundingRect::center() {
	return _center;
}
float BoundingRect::top() {
	return -_center.y;
}
float BoundingRect::left() {
	return -_center.x;
}
float BoundingRect::bottom() {
	return top() + _height;
}
float BoundingRect::right() {
	return left() + _width;
}
sf::Vector2f BoundingRect::topLeft() {
	return sf::Vector2f(left(), top());
}
sf::Vector2f BoundingRect::topRight() {
	return sf::Vector2f(right(), top());
}
sf::Vector2f BoundingRect::bottomRight() {
	return sf::Vector2f(right(), bottom());
}
sf::Vector2f BoundingRect::bottomLeft() {
	return sf::Vector2f(left(), bottom());
}
float BoundingRect::width() {
	return _width;
}
float BoundingRect::height() {
	return _height;
}

void BoundingRect::setPos(const sf::Vector2f pos) {
	_position = pos;
}
void BoundingRect::setPos(const float x, const float y) {
	_position = sf::Vector2f(x, y);
}
void BoundingRect::setCenter(const sf::Vector2f center) {
	_center = center;
}
void BoundingRect::setCenter(const float x, const float y) {
	_center = sf::Vector2f(x, y);
}
void BoundingRect::setWidth(const float width) {
	_width = width;
}
void BoundingRect::setHeight(const float height) {
	_height = height;
}

bool BoundingRect::intersects(BoundingRect rect) {
	return (right() > rect.left() && left() < rect.right() &&
		bottom() > rect.top() && top() < rect.bottom());
}
bool BoundingRect::contains(sf::Vector2f point) {
	return (point.x > left() && point.x < right() &&
		point.y > top() && point.y < bottom());
}