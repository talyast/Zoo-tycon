#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//all resources of images aounds and animation
class GameResources
{
public:
	static GameResources& instance();

	//soil textures
	sf::Texture* getGrassTexture() { return m_grassTexture.get(); }
	sf::Texture* getPathTexture() { return m_pathTexture.get(); }
	sf::Texture* getTreeTexture() const { return m_treeTexture.get(); }
	sf::Texture* getRockTexture() const { return m_rockTexture.get(); }
	sf::Texture* getWaterTexture() const { return m_waterTexture.get(); }
	sf::Texture* getSnowTexture() const { return m_snowTexture.get(); }
	sf::Texture* getGateTexture() const { return m_gateTexture.get(); }
	sf::Texture* getdirtTexture() const { return m_dirtTexture.get(); }
	sf::Texture* getsavannahTexture() const { return m_savannahTexture.get(); }
	sf::Texture* getherbivorFoodTexture() const { return m_herbivorFoodTexture.get(); }
	sf::Texture* getpreditorFoodTexture() const { return m_preditorFoodTexture.get(); }

	//buttons textures
	sf::Texture* getStartButtonTexture() const { return m_startButtonTexture.get(); }
	sf::Texture* getResumeButtonTexture() const { return m_resumeButtonTexture.get(); }
	sf::Texture* getExitButtonTexture() const { return m_exitButtonTexture.get(); }
	sf::Texture* getAnimalsButtonTexture() const { return m_animalButtonTexture.get(); }
	sf::Texture* getStaffButtonTexture() const { return m_buildingButtonTexture.get(); }
	sf::Texture* getConstructionButtonTexture() const { return m_constructionToolBarTexture.get(); }
	sf::Texture* getSaveButtonTexture() const { return m_saveToolBarTexture.get(); }
	sf::Texture* getDeleteButtonTexture() const { return m_deleteButtonTexture.get(); }
	sf::Texture* getBuildingsButtonTexture() const { return m_buildingButtonTexture.get(); }
	sf::Texture* getMapBackgroundTexture() const { return m_mapBackgroundTexture.get(); }
	sf::Texture* getLionButtonTexture() const { return m_lionButtonTexture.get(); }
	sf::Texture* getLionessButtonTexture() const { return m_lionessButtonTexture.get(); }
	sf::Texture* getPollarBearButtonTexture() const { return m_pollarBearButtonTexture.get(); }
	sf::Texture* getElephantButtonTexture() const { return m_elephantButtonTexture.get(); }
	sf::Texture* getGiraffeButtonTexture() const { return m_giraffeButtonTexture.get(); }
	sf::Texture* getHippoButtonTexture() const { return m_hippoButtonTexture.get(); }
	

	sf::Texture* getRestroomBacktLeft() const { return m_RestroomBackLeftTexture.get(); }
	sf::Texture* getRestroomBackRight() const { return m_RestroomBackRightTexture.get(); }
	sf::Texture* getRestroomFrontLeft() const { return m_RestroomFrontLeftTexture.get(); }
	sf::Texture* getRestroomFrontRight() const { return m_RestroomFrontRightTexture.get(); }
	
	sf::Texture* getDrinkBacktLeft() const { return m_DrinkBackLeftTexture.get(); }
	sf::Texture* getDrinkBackRight() const { return m_DrinkBackRightTexture.get(); }
	sf::Texture* getDrinkFrontLeft() const { return m_DrinkFrontLeftTexture.get(); }
	sf::Texture* getDrinkFrontRight() const { return m_DrinkFrontRightTexture.get(); }

	sf::Texture* getBurgerBackRight() const { return m_BurgerBackRightTexture.get(); }
	sf::Texture* getBurgerFrontLeft() const { return m_BurgerFrontLeftTexture.get(); }
	sf::Texture* getBurgerFrontRight() const { return m_BurgerFrontRightTexture.get(); }
	sf::Texture* getBurgerBacktLeft() const { return m_BurgerBackLeftTexture.get(); }

	sf::Texture* getChickenBackLeft() const { return m_ChickenBackLeftTexture.get(); }
	sf::Texture* getChickenBackRight() const { return m_ChickenBackRightTexture.get(); }
	sf::Texture* getChickenFrontLeft() const { return m_ChickenFrontLeftTexture.get(); }
	sf::Texture* getChickenFrontRight() const { return m_ChickenFrontRightTexture.get(); }
	sf::Texture* getCuttonCandyLeft() const { return m_CuttonCandyLeftTexture.get(); }
	sf::Texture* getCuttonCandyRight() const { return m_CuttonCandyRightTexture.get(); }
	sf::Texture* getCuttonCandyBackRight() const { return m_CuttonCandyBackRightTexture.get(); }
	sf::Texture* getCuttonCandyBackLeft() const { return m_CuttonCandyBackLeftTexture.get(); }

	//guest
	sf::Texture* getWomenTexture() const { return m_WomenTexture.get(); }
	sf::Texture* getManTexture() const { return m_ManTexture.get(); }

	sf::Texture* getRotateLeft() const { return m_rotateLeft.get(); }
	sf::Texture* getRotateRight() const { return m_rotateRight.get(); }

	//toolbar Section
	sf::Texture* getToolBarTexture() const { return m_toolBarTexture.get(); }
	sf::Texture* getAnimalSideBarTexture() const { return m_animalSideBarTexture.get(); }
	sf::Texture* getFenceLeftButtonTexture() const { return m_fenceLeftTexture.get(); }
	sf::Texture* getFenceRightButtonTexture() const { return m_fenceRightTexture.get(); }
	sf::Texture* getFenceFrontLeftButtonTexture() const { return m_fenceFrontLeftTexture.get(); }
	sf::Texture* getFenceFrontRightButtonTexture() const { return m_fenceFrontRightTexture.get(); }
	sf::Texture* getStatusBarTexture() const { return m_statusBarTexture.get(); }
	sf::Texture* getStatusHappinnesBarTexture() const { return m_statusBarHappinessTexture.get(); }
	sf::Texture* getConstractionToolBarTexture() const { return m_constractionToolBarTexture.get(); }
	sf::Texture* getBuildingSideBarTexture() const { return m_buildingSideBarTexture.get(); }

	//animals textures
	sf::Texture* getLionTexture() const { return m_lionTexture.get(); }
	sf::Texture* getLionessTexture() const { return m_lionessTexture.get(); }
	sf::Texture* getElephantTexture() const { return m_elephantTexture.get(); }
	sf::Texture* getGiraffeTexture() const { return m_giraffeTexture.get(); }
	sf::Texture* getHippoTexture() const { return m_hippoTexture.get(); }
	sf::Texture* getPolarBearTexture() const { return m_polarBearTexture.get(); }
	

	//animals buffers

	sf::SoundBuffer* getElephantEatBuffer() const { return m_elephantEatBuffer.get(); }
	sf::SoundBuffer* getElephantDrinkBuffer() const { return m_elephantDrinkBuffer.get(); }
	sf::SoundBuffer* getElephantTrumpBuffer() const { return m_elephantTrumpetBuffer.get(); }
	sf::SoundBuffer* getElephantTrunkNoiseBuffer() const { return m_elephantTrunkNoisetBuffer.get(); }
	sf::SoundBuffer* getElephantRumbleBuffer() const { return m_elephantRumbleBuffer.get(); }

	sf::SoundBuffer* getBearPollarEatBuffer() const { return m_BearPollarEatBuffer.get(); }
	sf::SoundBuffer* getBearPollarRoarBuffer() const { return m_BearPollarRoarBuffer.get(); }
	sf::SoundBuffer* getBearPollarGrowlBuffer() const { return m_BearPollarGrowlBuffer.get(); }


	sf::SoundBuffer* getHippoEatBuffer() const { return m_HippoEatBuffer.get(); }
	sf::SoundBuffer* getHippoWattertossBuffer() const { return m_HippoWattertossBuffer.get(); }
	sf::SoundBuffer* getHippoRoarBuffer() const { return m_HippoRoarBuffer.get(); }

	sf::SoundBuffer* getLionRoarBuffer() const { return m_LionRoarBuffer.get(); }
	sf::SoundBuffer* getLionEatBuffer() const { return m_LionEatBuffer.get(); }
	sf::SoundBuffer* getLionplayRoarBuffer() const { return m_LionplayRoarBuffer.get(); }
	sf::SoundBuffer* getLionBitBuffer() const { return m_LionBitBuffer.get(); }

	sf::SoundBuffer* getBgGameBuffer() const { return m_bgGameSound.get(); }
	sf::SoundBuffer* getBgMenuBuffer() const { return m_bgMenuSound.get(); }

	

	sf::Font* getTextFont() const { return m_textFont.get(); }

private:
	GameResources();
	GameResources(const GameResources& other) = default;
	GameResources& operator=(const GameResources& other) = default;

	std::unique_ptr<sf::Texture> m_gateTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_grassTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_pathTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_waterTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_snowTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_rockTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_treeTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_dirtTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_savannahTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_herbivorFoodTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_preditorFoodTexture = std::make_unique<sf::Texture>();
	

	std::unique_ptr<sf::Texture> m_buildingSideBarTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_constractionToolBarTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_animalSideBarTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_fenceFrontRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_fenceFrontLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_fenceRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_fenceLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_fenceTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_rockFenceTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_rockFenceGateTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_brikFenceTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_brikFenceGategTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_startButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_resumeButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_exitButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_animalButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_buildingButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_constructionToolBarTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_saveToolBarTexture = std::make_unique<sf::Texture>();//
	std::unique_ptr<sf::Texture> m_deleteButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_mapBackgroundTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_lionButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_lionessButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_elephantButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_pollarBearButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_giraffeButtonTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_hippoButtonTexture = std::make_unique<sf::Texture>();



	std::unique_ptr<sf::Texture> m_lionTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_lionessTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_elephantTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_giraffeTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_polarBearTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_hippoTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_toolBarTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_statusBarTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_statusBarHappinessTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_gate = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_DrinkBackLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_DrinkBackRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_DrinkFrontLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_DrinkFrontRightTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_RestroomBackLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_RestroomBackRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_RestroomFrontLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_RestroomFrontRightTexture = std::make_unique<sf::Texture>();
	
	std::unique_ptr<sf::Texture> m_BurgerBackLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_BurgerBackRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_BurgerFrontLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_BurgerFrontRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_ChickenBackLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_ChickenBackRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_ChickenFrontLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_ChickenFrontRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_CuttonCandyLeftTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_CuttonCandyRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_CuttonCandyBackRightTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_CuttonCandyBackLeftTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_WomenTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_ManTexture = std::make_unique<sf::Texture>();

	std::unique_ptr<sf::Texture> m_rotateRight = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> m_rotateLeft = std::make_unique<sf::Texture>();



	std::unique_ptr<sf::SoundBuffer> m_elephantEatBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_elephantDrinkBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_elephantTrumpetBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_elephantTrunkNoisetBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_elephantRumbleBuffer = std::make_unique<sf::SoundBuffer>();
	
	std::unique_ptr<sf::SoundBuffer> m_BearPollarEatBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_BearPollarRoarBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_BearPollarGrowlBuffer = std::make_unique<sf::SoundBuffer>();



	std::unique_ptr<sf::SoundBuffer> m_HippoEatBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_HippoWattertossBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_HippoRoarBuffer = std::make_unique<sf::SoundBuffer>();
	
	std::unique_ptr<sf::SoundBuffer> m_LionRoarBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_LionEatBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_LionplayRoarBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_LionBitBuffer = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_bgGameSound = std::make_unique<sf::SoundBuffer>();
	std::unique_ptr<sf::SoundBuffer> m_bgMenuSound = std::make_unique<sf::SoundBuffer>();

	std::unique_ptr<sf::Font> m_textFont = std::make_unique<sf::Font>();
};

