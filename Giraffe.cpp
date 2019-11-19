#include "Giraffe.h"
#include "Factory.h"
#include "GameResources.h"
const char symbol = 'g';
const std::string Giraffe::NAME = "Giraffe";
bool Giraffe::m_registerIt = Factory::registerAnimal(NAME, []() -> std::unique_ptr<Animal> { return std::make_unique<Giraffe>(); });
const float WALK_SPEED = 85.0f;
const float RUN_SPEED = 120.0f;
const float IMAGE_SIZE_X = 100.0f;
const float IMAGE_SIZE_Y = 100.0f;


// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_WALK_LEFT = 2;
const size_t ANIM_WALK_RIGHT = 3;
const size_t ANIM_EAT_FRONT = 4;
const size_t ANIM_EAT_BACK = 5;
const size_t ANIM_REST_FRONT = 6;
const size_t ANIM_REST_BACK = 7;
const size_t ANIM_STAND_UP_POSITION = 8;
const size_t ANIM_STAND_DOWN_POSITION = 9;
const size_t NUM_OF_ANIMATIONS = 10;

// animation data
const sf::Vector2f IMAGE_SIZE{ 120, 120 };

const sf::Vector2u IMAGE_COUNT{ 20, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 8,11 };
const sf::Vector2u IMAGE_RANGE_WALK_DOWN{ 12,15 };
const sf::Vector2u IMAGE_RANGE_EAT_FRONT{ 2,4 };
const sf::Vector2u IMAGE_RANGE_EAT_BACK{ 5,7 };
const sf::Vector2u IMAGE_RANGE_REST_FRONT{ 16,16 };
const sf::Vector2u IMAGE_RANGE_REST_BACK{ 17,17 };
const sf::Vector2u IMAGE_RANGE_FACE_FRONT{ 0,0 };
const sf::Vector2u IMAGE_RANGE_FACE_BACK{ 1,1 };



Giraffe::Giraffe()
{
	(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_REST_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_REST_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_FRONT, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getGiraffeTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_BACK,  false, IMAGE_SIZE
		), std::make_unique<Sound>());
	

	m_symbol = symbol;
}

void Giraffe::computeOffset(float deltaTime)
{

	switch (m_action)
	{
	case ANIM_WALK_UP:
		walkAnimation();
		m_offset = { -getSpeed().x * deltaTime , -getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_DOWN:
		walkDownAnimation();
		m_offset = { getSpeed().x * deltaTime , getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_LEFT:
		walkLeftAnimation();
		m_offset = { -getSpeed().x * deltaTime , getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_RIGHT:
		walkRightAnimation();
		m_offset = { getSpeed().x * deltaTime , -getSpeed().y * deltaTime };
		break;

	}

}

void Giraffe::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void Giraffe::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::changeScale();
}

void Giraffe::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::setDefaultScale();
}

void Giraffe::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	DynamicItem::changeScale();
}

void Giraffe::eatAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_FRONT);
}

void Giraffe::eatBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_BACK);
}

void Giraffe::runAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	//ronnnnn!!!!!!
	//set speed!!!
}

void Giraffe::runDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	//ronnnnn!!!!!!
	//set speed!!! 
}
void Giraffe::standFrontAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_UP_POSITION);
}

void Giraffe::standBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_DOWN_POSITION);
}
void Giraffe::specialAnimation()
{
	int num = rand() % 2;
	switch (num)
	{
	case 0:
		DynamicItem::changeAnimation(ANIM_REST_FRONT);
		break;
	case 1:
		DynamicItem::changeAnimation(ANIM_REST_BACK);
		break;
	default:
		break;
	}
}

