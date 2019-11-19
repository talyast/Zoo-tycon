#include "Elephant.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = 'e';
//const int happiness = 100;
const float SWITCH_DIRECTION_TIME = 3.0f;
const std::string Elephant::NAME = "Elephant";
bool Elephant::m_registerIt = Factory::registerAnimal(NAME, []() -> std::unique_ptr<Animal> { return std::make_unique<Elephant>(); });
const float WALK_SPEED = 5.0f;
const float RUN_SPEED = 20.0f;


// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_WALK_LEFT = 2;
const size_t ANIM_WALK_RIGHT = 3;
const size_t ANIM_EAT_FRONT = 4;
const size_t ANIM_EAT_BACK = 5;
const size_t ANIM_REST_FRONT = 6;
const size_t ANIM_REST_BACK = 7;
const size_t ANIM_STRACH = 8;
const size_t ANIM_STAND_UP_POSITION = 9;
const size_t ANIM_STAND_DOWN_POSITION = 10;
const size_t NUM_OF_ANIMATIONS = 11;


// animation data
const sf::Vector2f IMAGE_SIZE{ 135, 135 };
const sf::Vector2u IMAGE_COUNT{ 40, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 14,17 };
const sf::Vector2u IMAGE_RANGE_WALK_DOWN{ 10,13 };
const sf::Vector2u IMAGE_RANGE_EAT_FRONT{ 2,5 };
const sf::Vector2u IMAGE_RANGE_EAT_BACK{ 6,9 };
const sf::Vector2u IMAGE_RANGE_REST_FRONT{ 18,23 };
const sf::Vector2u IMAGE_RANGE_REST_BACK{ 23,28 };
const sf::Vector2u IMAGE_RANGE_STRACH{ 29,36 };
const sf::Vector2u IMAGE_RANGE_FACE_FRONT{ 0,0 };
const sf::Vector2u IMAGE_RANGE_FACE_BACK{ 1,1 };

Elephant::Elephant()
{
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE),
		std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_DOWN, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getElephantEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_EAT_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getElephantEatBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_REST_FRONT, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getElephantTrumpBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_REST_BACK, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getElephantRumbleBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_STRACH, false, IMAGE_SIZE
		), std::make_unique<Sound>(GameResources::instance().getElephantTrumpBuffer()));
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_FRONT, true, IMAGE_SIZE
		), std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getElephantTexture(), IMAGE_COUNT, IMAGE_RANGE_FACE_BACK, true, IMAGE_SIZE
		), std::make_unique<Sound>());

	m_symbol = symbol;
	//m_happiness = happiness;
}

void Elephant::computeOffset(float deltaTime)
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
	//case ANIM_REST_BACK:
	//	break;
	//case ANIM_STRACH:
	//	break;
	//case ANIM_STAND_DOWN_POSITION:
	//	break;
	//default:
	//	changeAnimation(ANIM_STAND_UP_POSITION);
	//	break;
	}

}

void Elephant::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void Elephant::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::changeScale();
}

void Elephant::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	DynamicItem::setDefaultScale();
}

void Elephant::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	DynamicItem::changeScale();
}

void Elephant::eatAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_FRONT);
}

void Elephant::eatBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_EAT_BACK);
}

void Elephant::runAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
	//ron!!!!!!!!!!!!
	//set speed!!!!!!
}

void Elephant::runDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
	//ron!!!!!!!!!!!!
	//set speed!!!!!!
}
void Elephant::standFrontAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_UP_POSITION);
}

void Elephant::standBackAnimation()
{
	DynamicItem::changeAnimation(ANIM_STAND_DOWN_POSITION);
}
void Elephant::specialAnimation()
{
	int num = rand() % 3;
	switch (num)
	{
	case 0:
		DynamicItem::changeAnimation(ANIM_REST_FRONT);
		break;
	case 1:
		DynamicItem::changeAnimation(ANIM_REST_BACK);
		break;
	case 2:
		DynamicItem::changeAnimation(ANIM_STRACH);
		break;
	default:
		break;
	}
}



