#include "Bullet.h"

void Bullet::setup(int fp, ofPoint p, float s, 
	ofImage * bullet_img)
{
	from_player = fp;
	pos = p;
	speed = s;
	img = bullet_img;
	width = img->getWidth();
}

void Bullet::update()
{
	switch (from_player) {
	case 0:
		pos.y += speed;
		break;
	case 1:
		pos.y -= speed;
		break;
	case 2:
		pos.y -= speed;
		pos.x += speed / 10;
		break;
	case 3:
		pos.y -= speed;
		pos.x -= speed / 10;
		break;
	}
}

void Bullet::draw() {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}