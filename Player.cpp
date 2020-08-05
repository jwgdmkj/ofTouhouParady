#include "Player.h"

//플레이어 셋업.
void Player::setup(ofImage * _img, ofPoint _pos, 
	bool visiblecenter, ofImage * _center)
{
	img = _img;
	height = img->getHeight();
	width = img->getWidth();
	pos.set(_pos);
	collisionpos.set(pos.x - width / 3, pos.y);
	speed = 3;
	lives = 5;
	visible = visiblecenter;
	center = _center;
	centerwidth = center->getWidth();
}

//업데이트는, 왼쪽이냐 오른쪽이냐에 따라 player의 xpos를 움직임 30프레임
void Player::update(bool visible) {
	if (is_up_pressed)
		pos.y -= speed;
	if (is_down_pressed)
		pos.y += speed;
	if (is_left_pressed)
		pos.x -= speed;
	if (is_right_pressed)
		pos.x += speed;
}

//플레이어 그리기
void Player::draw(bool visible) 
{
	img->draw(pos.x - width / 2, pos.y - height / 2);
	if (visible)
		center->draw(pos.x-width/3, pos.y);
}

void Player::shoot() 
{
}
