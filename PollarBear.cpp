#include "PollarBear.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = 'p';
const std::string PollarBear::NAME = "PollarBear";
bool PollarBear::m_registerIt = Factory::registerAnimal(NAME, []() -> std::unique_ptr<Animal> { return std::make_unique<PollarBear>(); });
const float WALK_SPEED = 100.0f;
const float RUN_SPEED = 150.0f;
const float IMAGE_SIZE_X = 80.0f;
const float IMAGE_SIZE_Y = 80.0f;

// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_EAT_FRONT = 2;
const size_t ANIM_WALK_LEFT = 3;
const size_t ANIM_WALK_RIGHT = 4;
const size_t ANIM_EAT_BACK = 5;
const size_t ANIM_RUN_UP = 6;
const size_t ANIM_RUN_DOWN = 7;
const size_t ANIM_SIT_FRONT = 8;
const size_t ANIM_SIT_BACK = 9;
const size_t ANIM_STAND_FRONT_POSITION = 9;
const size_t ANIM_STAND_BACK_POSITION = 9;
const size_t NUM_OF_ANIMATIONS = 10;


// animation data
const sf::Vector2f IMAGE_SIZE{ 80, 80 };
const sf::Vector2u IMAGE_COUNT{ 32, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 12,15 };
const sf::Vector2u IMAGE_RANGE_WALK_DOWN{ 8,11 };
const sf::Vector2u IMAGE_RANGE_EAT_FRONT{ 2,4 };
const sf::Vector2u IMAGE_RANGE_EAT_BACK{ 4,6 };
const sf::Vector2u IMAGE_RANGE_RUN_UP{ 20,23 };
const sf::Vector2u IMAGE_RANGE_RUN_DOWN{ 16,19 };
const sf::Vector2u IMAGE_RANGE_SIT_FRONT{ 24,27 };
const sf::Vector2u IMAGE_RANGE_SIT_BACK{ 28,31 };
const sf::Vector2u IMAGE_RANGE_FACE_FRONT{ 0,0 };
const sf::Vector2u IMAGE_RANGE_FACE_BACK{ 1,1 };


PollarBear::PollarBear()
{

	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getBearPollarEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getBearPollarEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_RUN_UP, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_RUN_DOWN, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_SIT_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_SIT_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_FRONT, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getPolarBearTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>());
	m_symbol = symbol;

}

void PollarBear::computeOffset(float deltaTime)
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

void PollarBear::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void PollarBear::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::changeScale();
}

void PollarBear::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::setDefaultScale();
}

void PollarBear::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	DynamicItem::changeScale();
}

void PollarBear::eatAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_FRONT);
}

void PollarBear::eatBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_BACK);
}

void PollarBear::runAnimation()
{
	DynamicItem::changeAnimation(ANIM_RUN_UP);
}

void PollarBear::runDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_RUN_DOWN);
}
void PollarBear::standFrontAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_FRONT_POSITION);
}

void PollarBear::standBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_BACK_POSITION);
}

void PollarBear::specialAnimation()
{
	int num = rand() % 2;
	switch (num)
	{
	case 0:
		DynamicItem::changeAnimation(ANIM_SIT_FRONT);
		break;
	case 1:
		DynamicItem::changeAnimation(ANIM_SIT_FRONT);
		break;
	default:
		break;
	}
}

