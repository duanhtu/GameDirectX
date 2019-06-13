#include "GameConfiguration.h"

map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();
		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));
		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));
		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("object_default_ay", -180));

		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 60)); 
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vy_jump", 130));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_time", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_delay", 2000));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_invisible_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_invisible_time", 30));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vx", 30));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vy", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_shuriken_vx", 200));

		globalsConfigurationDouble->insert(pair<const char*, double>("samurai_distance_to_activ", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("samurai_distance_to_attack",70));
		globalsConfigurationDouble->insert(pair<const char*, double>("samurai_vx", 60));

		globalsConfigurationDouble->insert(pair<const char*, double>("cheetah_distance_to_activ", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("cheetah_vx", 100));

		globalsConfigurationDouble->insert(pair<const char*, double>("death_distance_to_activ", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("death_vx", 40));
		globalsConfigurationDouble->insert(pair<const char*, double>("death_weapon_vx", 40));
		globalsConfigurationDouble->insert(pair<const char*, double>("death_weapon_vy", 130));
		globalsConfigurationDouble->insert(pair<const char*, double>("death_time_run", 2000));
		globalsConfigurationDouble->insert(pair<const char*, double>("death_time_fire", 1000));

		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_distance_to_activ", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_vx", 60));
		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_fire_time", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_bullet_vx", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_run_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("solicol_fire_delay", 1000));

		globalsConfigurationDouble->insert(pair<const char*, double>("bird_r", 2));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_min_x", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_max_x", 50));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_active_length", 200));

		globalsConfigurationDouble->insert(pair<const char*, double>("solibaz_distance_to_activ", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("solibaz_vx", 0));
		globalsConfigurationDouble->insert(pair<const char*, double>("solibaz_bullet_vx", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("solibaz_fire_time", 1500));
		globalsConfigurationDouble->insert(pair<const char*, double>("solibaz_fire_delay", 1500));

		globalsConfigurationDouble->insert(pair<const char*, double>("runner_distance_to_activ", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("runner_vx", 100));

		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vx", 90));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vy", 165));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_stand_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_dying_delay", 8000));
	}
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		globalsConfigurationString->insert(pair<const char*, const char*>("window_title", "Ninja Gaiden"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));

		

	}
	return globalsConfigurationString->at(key);
}

GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}
