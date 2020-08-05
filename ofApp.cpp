#include "ofApp.h"

void ofApp::setup() {
	//게임판 설치
	game_state = "start";
	score = 0;

	max_enemy_amplitude = 3.0;
	max_enemy_shoot_interval = 1.5;

	player_image.load("images/player.png");
	player_bullet_image.load("images/player_bullet.png");
	center_image.load("images/Center.png");
//	player_bullet_sound.load("sounds/player_bullet.mp3");
	enemy_image.load("images/enemy.png");
	enemy_bullet_image.load("images/enemy_bullet.png");
	start_button.load("images/start_button.png");
	exit_button.load("images/exit.png");
	instructer.load("images/Enemy_bullet2.png");
	stage1.load("images/stage1.png");
	stage2.load("images/stage2.png");
	stage3.load("images/stage3.png");

	player_start.set(256, 650);

	float width = 50;
	float height = 50;

	player_1.setup(&player_image, player_start, visiblecenter,
	&center_image);

	start_screen.load("images/startScreen.png");
	end_screen.load("images/end_screen.png");
	score_font.load("fonts/steelworks_vintage.otf", 48);
	lobby_screen.load("images/lobby_image.png");
//	ofSetFrameRate(15);

//	ofSetLineWidth(4);
}

void ofApp::update() {
	if (game_state == "start")
	{

	}

	else if (game_state == "lobby")
	{

	}

	else if (game_state == "game")
	{
		player_1.update(visiblecenter);
		limitPlayer(&player_1.pos);
		update_bullets();

		for (int i = 0; i < enemies.size(); i += 1)
		{
			enemies[i].update();
			if (enemies[i].time_to_shoot())
			{
				Bullet b;
				b.setup(0, enemies[i].pos, enemies[i].speed,
					&enemy_bullet_image);
				bullets.push_back(b);
			}
		}

		if (level_controller.should_spawn() == true)
		{
			Enemy e;
			e.setup(max_enemy_amplitude,
				max_enemy_shoot_interval, &enemy_image);
			enemies.push_back(e);
		}
	}

	else if (game_state == "end");
	{
	}

}

void ofApp::draw() {
	if (game_state == "start")
	{
		start_screen.draw(0, 0);
		start_button.draw(ofGetWidth()/3, ofGetHeight()/3);
		exit_button.draw(ofGetWidth() / 3,
			70 + ofGetHeight() / 3);

		if (buttonnum == 0)
			instructer.draw(ofGetWidth() / 3 - 20,
				30 + ofGetHeight() / 3);
		else
			instructer.draw(ofGetWidth() / 3 - 20,
				100 + ofGetHeight() / 3);
	}

	if (game_state == "lobby")
	{
		lobby_screen.draw(0, 0);
		stage1.draw(2* ofGetWidth() / 3, ofGetHeight() / 8);
		stage2.draw(2* ofGetWidth() / 3,
			80 + ofGetHeight() / 8);
		stage3.draw(2* ofGetWidth() / 3,
			160 + ofGetHeight() / 8);

		if (lobbybutton == 0)
			instructer.draw(2 * ofGetWidth() / 3 - 20,
				30+ ofGetHeight() / 8);
		else if(lobbybutton == 1)
			instructer.draw(2 * ofGetWidth() / 3 - 20,
				110 + ofGetHeight() / 8);
		else if (lobbybutton == 2)
			instructer.draw(2* ofGetWidth() / 3 - 20,
				190 + ofGetHeight() / 8);

	}

	else if (game_state == "game")
	{
		ofBackground(0, 0, 0);
		ofDrawRectangle(leftscreen, upscreen,
			rightscreen, downscreen);
		for (int i = 0; i < enemies.size(); ++i)
			enemies[i].draw();

		for (int i = 0; i < bullets.size(); ++i)
			bullets[i].draw();

		player_1.draw(visiblecenter);
		draw_score();
		draw_lives();
	}

	else if (game_state == "end")
		end_screen.draw(0, 0);
}

void ofApp::keyPressed(int key) {
	if (game_state == "start")
	{
		if (key == OF_KEY_DOWN)
		{
			buttonnum++;
			if (buttonnum > 2)
				buttonnum = 1;
		}
		if (key == OF_KEY_UP)
		{
			buttonnum--;
			if (buttonnum < 0)
				buttonnum = 0;
		}
	}

	if (game_state == "lobby")
	{
		if (key == OF_KEY_DOWN)
		{
			lobbybutton++;
			if (lobbybutton > 3)
				lobbybutton = 2;
		}
		if (key == OF_KEY_UP)
		{
			lobbybutton--;
			if (lobbybutton < 0)
				lobbybutton = 0;
		}
	}

	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
			player_1.is_left_pressed = true;
		if (key == OF_KEY_RIGHT)
			player_1.is_right_pressed = true;
		if (key == OF_KEY_UP)
			player_1.is_up_pressed = true;
		if (key == OF_KEY_DOWN)
			player_1.is_down_pressed = true;

		if (key == OF_KEY_SHIFT)
		{
			player_1.speed = 1.5;
			visiblecenter = true;
		}

		if(key==' ')
		{
			Bullet b1;
			Bullet b2;
			Bullet b3;

			b1.setup(1, player_1.pos, 10,
				&player_bullet_image);
			b2.setup(2, player_1.pos, 10,
				&player_bullet_image);
			b3.setup(3, player_1.pos, 10,
				&player_bullet_image);

			bullets.push_back(b1);
			bullets.push_back(b2);
			bullets.push_back(b3);
		//	player_bullet_sound.play();
		}
	}
}

void ofApp::keyReleased(int key) {
	if (game_state == "start")
	{
		if (buttonnum == 0 && key == OF_KEY_RETURN)
		{
			game_state = "lobby";
		}

		else if (buttonnum == 1 && key == OF_KEY_RETURN)
		{
			game_state = "end";
		}
	}

	else if (game_state == "lobby")
	{
		if (lobbybutton == 0 && key == OF_KEY_RETURN)
		{
			game_state = "game";
			level_controller.setup(ofGetElapsedTimeMillis());
		}
	}

	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
			player_1.is_left_pressed = false;
		if (key == OF_KEY_RIGHT)
			player_1.is_right_pressed = false;
		if (key == OF_KEY_UP)
			player_1.is_up_pressed = false;
		if (key == OF_KEY_DOWN)
			player_1.is_down_pressed = false;

		if (key == OF_KEY_SHIFT)
		{
			player_1.speed = 3;
			visiblecenter = false;
		}
	}
}

void ofApp::update_bullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
		if (bullets[i].pos.y - bullets[i].width / 2 < 0
			|| bullets[i].pos.y + bullets[i].width / 2 >
			ofGetHeight())
		{
			bullets.erase(bullets.begin() + i);
		}
	}
	check_bullet_collisions();
//	check_bullet_out();
}

//checkcollision이 참일 때, 해당 water을 vector내에서 erase
void ofApp::check_bullet_collisions() 
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].from_player)
		{
			for (int e = enemies.size() - 1; e >= 0; e--)
			{
				if (ofDist(bullets[i].pos.x, bullets[i].pos.y,
					enemies[e].pos.x, enemies[e].pos.y) <
					(enemies[e].width + bullets[i].width) / 2)
				{
					enemies.erase(enemies.begin() + e);
					bullets.erase(bullets.begin() + i);
					score += 10;
				}
			}
		}

		else {
			if (ofDist(bullets[i].pos.x, bullets[i].pos.y,
				player_1.pos.x, player_1.pos.y)
				< (bullets[i].width + player_1.centerwidth) / 2)
			{
				bullets.erase(bullets.begin() + i);
				player_1.lives--;

				if (player_1.lives <= 0)
					game_state = "end";
			}
		}
	}
}

//void ofApp::check_bullet_out()
//{
//	for (int i = 0; i < bullets.size(); i++)
//	{
//		if (bullets[i].from_player)
//		{
//			if (bullets[i].pos.x > rightscreen + leftscreen)
//				bullets.erase(bullets.begin() + i);
//			if (bullets[i].pos.x < leftscreen)
//				bullets.erase(bullets.begin() + i);
//			if (bullets[i].pos.x > upscreen + downscreen)
//				bullets.erase(bullets.begin() + i);
//			if (bullets[i].pos.x < downscreen)
//				bullets.erase(bullets.begin() + i);
//		}
	
//	}
//}

void ofApp::limitPlayer(ofPoint * point)
{
	if (point->x < leftscreen)
		point->x = leftscreen;
	if(point->x > leftscreen + rightscreen)
		point->x = leftscreen + rightscreen;
	if (0 > upscreen) 
		point->y = upscreen;
	if (point->y > upscreen + downscreen) 
		point->y = upscreen + downscreen;
}

void ofApp::draw_lives()
{
	for (int i = 0; i < player_1.lives; i++) {
		player_image.draw(ofGetWidth()
			- (i * player_image.getWidth()) - 100, 30);
	}
}

void ofApp::draw_score()
{
	if (game_state == "game")
		score_font.drawString(ofToString(score), 
			9* ofGetWidth()/10, ofGetHeight()/4);
	else if (game_state == "end")
	{
		float w = score_font.stringWidth(ofToString(score));
		score_font.drawString(ofToString(score), ofGetWidth() / 2
			- w / 2, ofGetHeight() / 2 + 100);
	}
}

void ofApp::reset_game() 
{

}

void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}