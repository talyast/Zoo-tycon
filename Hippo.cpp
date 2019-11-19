#include "Hippo.h"
#include "Factory.h"
#include "GameResources.h"
const char symbol = 'h';
const std::string Hippo::NAME = "Hippo";
bool Hippo::m_registerIt = Factory::registerAnimal(NAME, []() -> std::unique_ptr<Animal> { return std::make_unique<Hippo>(); });
const float WALK_SPEED = 50.0f;
const float RUN_SPEED = 100.0f;
const float IMAGE_SIZE_X = 80.0f;
const float IMAGE_SIZE_Y = 80.0f;

// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_EAT_FRONT = 2;
const size_t ANIM_WALK_LEFT = 3;
const size_t ANIM_EAT_BACK = 4;
const size_t ANIM_WALK_RIGHT = 5;
const size_t ANIM_GROWL_FRONT = 6;
const size_t ANIM_GROWL_BACK = 7;
const size_t ANIM_SWIM_FRONT = 8;
const size_t ANIM_SWIM_BACK = 9;
const size_t ANIM_STAND_UP_POSITION = 9;
const size_t ANIM_STAND_DOWN_POSITION = 9;
const size_t NUM_OF_ANIMATIONS = 10;

// animation data
const sf::Vector2f IMAGE_SIZE{ 80, 80 };

const sf::Vector2u IMAGE_COUNT{ 32, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 14,17 };
const sf::Vector2u IMAGE_RANGE_WALK_DOWN{ 10,13 };
const sf::Vector2u IMAGE_RANGE_EAT_FRONT{ 2,5 };
const sf::Vector2u IMAGE_RANGE_EAT_BACK{ 6,9 };
const sf::Vector2u IMAGE_RANGE_GROWL_FRONT{ 18,21 };
const sf::Vector2u IMAGE_RANGE_GROWL_BACK{ 22,25 };
const sf::Vector2u IMAGE_RANGE_SWIM_FRON{ 27,29 };
const sf::Vector2u IMAGE_RANGE_SWIM_BACK{ 30,33 };
const sf::Vector2u IMAGE_RANGE_FACE_FRONT{ 0,0 };
const sf::Vector2u IMAGE_RANGE_FACE_BACK{ 1,1 };

Hippo::Hippo()
{

	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP,  true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_FRONT,  false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_BACK,  false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_GROWL_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getHippoRoarBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_GROWL_BACK,  false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getHippoRoarBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_SWIM_FRON,  true, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getHippoRoarBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_SWIM_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getHippoWattertossBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_FRONT, true, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getHippoWattertossBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getHippoTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	

	m_symbol = symbol;
}

void Hippo::computeOffset(float deltaTime)
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

void Hippo::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void Hippo::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::changeScale();
}

void Hippo::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::setDefaultScale();
}

void Hippo::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	DynamicItem::changeScale();
}

void Hippo::eatAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_FRONT);
}

void Hippo::eatBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_BACK);
}

void Hippo::runAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	//ronnnnn!!!!!!
	//set speed!!! 
}

void Hippo::runDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	//ronnnnn!!!!!!
	//set speed!!! 
}
void Hippo::standFrontAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_UP_POSITION);
}

void Hippo::standBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_DOWN_POSITION);
}
void Hippo::specialAnimation()
{
	int num = rand() % 4;
	switch (num)
	{
	case 0:
		DynamicItem::changeAnimation(ANIM_GROWL_FRONT);
		break;
	case 1:
		DynamicItem::changeAnimation(ANIM_GROWL_BACK);
		break;
	case 2:
		DynamicItem::changeAnimation(ANIM_SWIM_FRONT);
		break;
	case 3:
		DynamicItem::changeAnimation(ANIM_SWIM_BACK);
		break;
	default:
		break;
	}
}

void Hippo::waterAnimation()
{
	changeAnimation(ANIM_SWIM_FRONT);
}

