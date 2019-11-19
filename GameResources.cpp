#include "GameResources.h"




GameResources& GameResources::instance()
{
	static GameResources instance;
	return instance;
}

GameResources::GameResources()
{


	if (!m_WomenTexture->loadFromFile("img/woman1.png"))
		throw std::exception();
	//if (!m_ManTexture->loadFromFile("img/man.png"))
	//	throw std::exception();

	if (!m_dirtTexture->loadFromFile("img/dirt.png"))
		throw std::exception();
	if (!m_savannahTexture->loadFromFile("img/savannah.png"))
		throw std::exception();

	if (!m_herbivorFoodTexture->loadFromFile("img/herbivorFood.png"))
		throw std::exception();
	if (!m_preditorFoodTexture->loadFromFile("img/preditorFood.png"))
		throw std::exception();



	if (!m_grassTexture->loadFromFile("img/grass.png"))
		throw std::exception();
	if (!m_snowTexture->loadFromFile("img/snow.png"))
		throw std::exception();
	if (!m_waterTexture->loadFromFile("img/water.png"))
		throw std::exception();
	if (!m_pathTexture->loadFromFile("img/path.png"))
		throw std::exception();
	if (!m_rockTexture->loadFromFile("img/Rock.png"))
		throw std::exception();
	if (!m_treeTexture->loadFromFile("img/tree.png"))
		throw std::exception();
	if (!m_gateTexture->loadFromFile("img/gate.png"))
		throw std::exception();
	if (!m_startButtonTexture->loadFromFile("img/start_button.png"))
		throw std::exception();
	if (!m_resumeButtonTexture->loadFromFile("img/resume_button.png"))
		throw std::exception();
	if (!m_exitButtonTexture->loadFromFile("img/exit_button.png"))
		throw std::exception();
	if (!m_animalButtonTexture->loadFromFile("img/animals_button.png"))
		throw std::exception();
	if (!m_buildingButtonTexture->loadFromFile("img/building_button.png"))
		throw std::exception();
	if (!m_deleteButtonTexture->loadFromFile("img/delete_button.png"))
		throw std::exception();
	if (!m_constructionToolBarTexture->loadFromFile("img/construction_button.png"))
		throw std::exception();
	if (!m_mapBackgroundTexture->loadFromFile("img/menu_background.jpg"))
		throw std::exception();
	if (!m_toolBarTexture->loadFromFile("img/tool_bar.png"))
		throw std::exception();
	if (!m_lionButtonTexture->loadFromFile("img/lion_button.png"))
		throw std::exception();
	if (!m_lionessButtonTexture->loadFromFile("img/lioness_button1.png"))
		throw std::exception();
	if (!m_giraffeButtonTexture->loadFromFile("img/giraffe_button.png"))
		throw std::exception();
	if (!m_hippoButtonTexture->loadFromFile("img/hippo_button.png"))
		throw std::exception();
	if (!m_animalSideBarTexture->loadFromFile("img/AnimalToolBar_3.png"))
		throw std::exception();
	if (!m_brikFenceTexture->loadFromFile("img/briks_fence.png"))
		throw std::exception();
	if (!m_brikFenceGategTexture->loadFromFile("img/briks_fence_gate.png"))
		throw std::exception();
	if (!m_fenceTexture->loadFromFile("img/fence.png"))
		throw std::exception();
	if (!m_rockFenceGateTexture->loadFromFile("img/rock_fence.png"))
		throw std::exception();
	if (!m_rockFenceTexture->loadFromFile("img/rock_fence_gate.png"))
		throw std::exception();
	if (!m_fenceLeftTexture->loadFromFile("img/fence_left_open.png"))
		throw std::exception();
	if (!m_fenceRightTexture->loadFromFile("img/fence_right_open.png"))
		throw std::exception();
	if (!m_fenceFrontLeftTexture->loadFromFile("img/fence_front_left_open.png"))
		throw std::exception();
	if (!m_fenceFrontRightTexture->loadFromFile("img/fence_front_right_open.png"))
		throw std::exception();
	if (!m_constractionToolBarTexture->loadFromFile("img/constractionToolBar.png"))
		throw std::exception();
	if (!m_buildingSideBarTexture->loadFromFile("img/BuildingToolBar.png"))
		throw std::exception();
	if (!m_statusBarHappinessTexture->loadFromFile("img/happiness_toolbar.png"))
		throw std::exception();
	if (!m_saveToolBarTexture->loadFromFile("img/save_game.png"))
		throw std::exception();
	


	if (!m_elephantButtonTexture->loadFromFile("img/elephant_button.png"))
		throw std::exception();
	if (!m_pollarBearButtonTexture->loadFromFile("img/bear_button.png"))
		throw std::exception();

	if (!m_statusBarTexture->loadFromFile("img/status_bar.png"))
		throw std::exception();
	

	if (!m_elephantTexture->loadFromFile("img/elephant_row.png"))
		throw std::exception();
	if (!m_lionTexture->loadFromFile("img/lion_row.png"))
		throw std::exception();
	if (!m_lionessTexture->loadFromFile("img/lioness_row.png"))
		throw std::exception();
	if (!m_giraffeTexture->loadFromFile("img/giraffe_row.png"))
		throw std::exception();
	if (!m_polarBearTexture->loadFromFile("img/pollar_bear_row.png"))
		throw std::exception();
	if (!m_hippoTexture->loadFromFile("img/hipo_row.png"))
		throw std::exception();

	if (!m_gateTexture->loadFromFile("img/gate.png"))
		throw std::exception();
	if (!m_DrinkBackLeftTexture->loadFromFile("img/drinkBackLeft.png"))
		throw std::exception();
	if (!m_DrinkBackRightTexture->loadFromFile("img/drinkBackRight.png"))
		throw std::exception();
	if (!m_DrinkFrontLeftTexture->loadFromFile("img/drinkFrontLeft.png"))
		throw std::exception();
	if (!m_DrinkFrontRightTexture->loadFromFile("img/drinkFrontRight.png"))
		throw std::exception();

	if (!m_RestroomBackLeftTexture->loadFromFile("img/restroomBackLeft.png"))
		throw std::exception();
	if (!m_RestroomBackRightTexture->loadFromFile("img/restroomBackRight.png"))
		throw std::exception();
	if (!m_RestroomFrontLeftTexture->loadFromFile("img/restroomFrontLeft.png"))
		throw std::exception();
	if (!m_RestroomFrontRightTexture->loadFromFile("img/restroomFrontRight.png"))
		throw std::exception();


	if (!m_BurgerBackLeftTexture->loadFromFile("img/burger_back_left.png"))
		throw std::exception();
	if (!m_BurgerBackRightTexture->loadFromFile("img/burger_back_right.png"))
		throw std::exception();
	if (!m_BurgerFrontLeftTexture->loadFromFile("img/burger_fron_left.png"))
		throw std::exception();
	if (!m_BurgerFrontRightTexture->loadFromFile("img/burger_fron_right.png"))
		throw std::exception();
	if (!m_ChickenBackLeftTexture->loadFromFile("img/chicken_back_left.png"))
		throw std::exception();
	if (!m_ChickenBackRightTexture->loadFromFile("img/chicken_back_right.png"))
		throw std::exception();
	if (!m_ChickenFrontLeftTexture->loadFromFile("img/chicken_front_left.png"))
		throw std::exception();
	if (!m_ChickenFrontRightTexture->loadFromFile("img/chicken_front_right.png"))
		throw std::exception();
	if (!m_CuttonCandyLeftTexture->loadFromFile("img/cuttonCandy_left.png"))
		throw std::exception();
	if (!m_CuttonCandyRightTexture->loadFromFile("img/cuttonCandy_right.png"))
		throw std::exception();
	if (!m_CuttonCandyBackLeftTexture->loadFromFile("img/cottonCandy_back_left.png"))
		throw std::exception();
	if (!m_CuttonCandyBackRightTexture->loadFromFile("img/cottonCandy_back_right.png"))
		throw std::exception();
	if (!m_rotateLeft->loadFromFile("img/turnLeft.png"))
		throw std::exception();
	if (!m_rotateRight->loadFromFile("img/turnRight.png"))
		throw std::exception();



	//animals buffers
	if (!m_elephantEatBuffer->loadFromFile("sound/elephant/ElephantAfrican_Adult_Eat.wav"))
		throw std::exception();
	if (!m_elephantTrumpetBuffer->loadFromFile("sound/elephant/ElephantAfrican_Adult_TrunkNoiseMaker.wav"))
		throw std::exception();
	if (!m_elephantRumbleBuffer->loadFromFile("sound/elephant/ElephantAfrican_Adult_RumbleB.wav"))
		throw std::exception();
	if (!m_elephantDrinkBuffer->loadFromFile("sound/elephant/ElephantAfrican_Adult_Drink.wav"))
		throw std::exception();

	if (!m_BearPollarEatBuffer->loadFromFile("sound/bear/BearPolar_Adult_EatA.wav"))
		throw std::exception();
	if (!m_BearPollarRoarBuffer->loadFromFile("sound/bear/BearPolar_Adult_RoarA.wav"))
		throw std::exception();

	if (!m_BearPollarGrowlBuffer->loadFromFile("sound/bear/BearPolar_Adult_RoarC.wav"))
		throw std::exception();

	if (!m_HippoEatBuffer->loadFromFile("sound/hippopotamus/Hippopotamus_Adult_EatA.wav"))
		throw std::exception();
	if (!m_HippoWattertossBuffer->loadFromFile("sound/hippopotamus/Hippopotamus_Adult_WaterToss.wav"))
		throw std::exception();
	if (!m_HippoRoarBuffer->loadFromFile("sound/hippopotamus/Hippopotamus_Adult_RoarB.wav"))
		throw std::exception();
	
	if (!m_LionBitBuffer->loadFromFile("sound/lion/Lion_Adult_Bit.wav"))
		throw std::exception();
	if (!m_LionRoarBuffer->loadFromFile("sound/lion/Lion_Adult_F_Roar.wav"))
		throw std::exception();
	if (!m_LionEatBuffer->loadFromFile("sound/lion/Lion_Adult_Eat.wav"))
		throw std::exception();
	if (!m_LionplayRoarBuffer->loadFromFile("sound/lion/Lion_Adult_M_Play_Roar.wav"))
		throw std::exception();


	if (!m_bgGameSound->loadFromFile("sound/general/game.wav"))
		throw std::exception();
	if (!m_bgMenuSound->loadFromFile("sound/general/openmusic.wav"))
		throw std::exception();

	
	if (!m_textFont->loadFromFile("font/Ariel_Insular.ttf"))
		throw std::exception();

}
