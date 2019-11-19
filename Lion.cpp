#include "Lion.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = 'l';
//const int happiness = 100;
const std::string Lion::NAME = "Lion";
bool Lion::m_registerIt = Factory::registerAnimal(NAME, []() -> std::unique_ptr<Animal> { return std::make_unique<Lion>(); });

const float WALK_SPEED = 150.0f;
const float RUN_SPEED = 200.0f;


// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_WALK_LEFT = 2;
const size_t ANIM_WALK_RIGHT = 3;
const size_t ANIM_EAT_FRONT = 4;
const size_t ANIM_EAT_BACK = 5;
const size_t ANIM_RUN_UP = 6;
const size_t ANIM_RUN_DOWN = 7;
const size_t ANIM_JUMP = 8;
const size_t ANIM_STAND_FRONT_POSITION = 9;
const size_t ANIM_STAND_BACK_POSITION = 10;
const size_t NUM_OF_ANIMATIONS = 9;


// animation data

const sf::Vector2f IMAGE_SIZE{ 70, 70 };
const sf::Vector2u IMAGE_COUNT{ 32, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 12,15 };
const sf::Vector2u IMAGE_RANGE_WALK_DOWN{ 9,12 };
const sf::Vector2u IMAGE_RANGE_EAT_FRONT{ 3,5 };
const sf::Vector2u IMAGE_RANGE_EAT_BACK{ 6,8 };
const sf::Vector2u IMAGE_RANGE_RUN_UP{ 22,25 };
const sf::Vector2u IMAGE_RANGE_RUN_DOWN{ 17,20 };
const sf::Vector2u IMAGE_RANGE_JUMP{ 26,33 };
const sf::Vector2u IMAGE_RANGE_FACE_FRONT{ 1,1 };
const sf::Vector2u IMAGE_RANGE_FACE_BACK{ 2,2 };




Lion::Lion()
{

	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getLionEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getLionEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_RUN_UP, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_RUN_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getLionRoarBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_JUMP, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getLionplayRoarBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_FRONT, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getLionTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	//changeAnimation();
	m_symbol = symbol;
}

void Lion::computeOffset(float deltaTime)
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

void Lion::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	
}

void Lion::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	
}

void Lion::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);

}

void Lion::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	
	
}

void Lion::eatAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_FRONT);
}

void Lion::eatBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_BACK);
}

void Lion::runAnimation()
{
	DynamicItem::changeAnimation(ANIM_RUN_UP);
}

void Lion::runDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_RUN_DOWN);
}

void Lion::standFrontAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_FRONT_POSITION);
}

void Lion::standBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_BACK_POSITION);
}

void Lion::specialAnimation()
{

	DynamicItem::changeAnimation(ANIM_JUMP);	
	
}
