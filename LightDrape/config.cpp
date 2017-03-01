#include "Config.h"

Config_ Config::mInstance = nullptr;

Config::Config()
{

}

void Config::init( char* file )
{
	std::string type;
	std::string ignore;
	std::ifstream configIn(file);
	while(!configIn.eof()){
		configIn >> type;
		if(type == "#"){
			getline(configIn, ignore);
			continue;
		}
		if(type == "human_in_path"){
			configIn >> humanInPath;
		}
		else if(type == "cloth_in_path"){
			configIn >> clothInPath;
		}
		else if(type == "human_in_file"){
			configIn >> humanInFileName;
		}
		else if(type == "cloth_in_file"){
			configIn >> clothInFileName;
		}
		else if(type == "cloth_out_path"){
			configIn >> clothOutPath;
		}
		else if(type == "human_mesh_diretion"){
			configIn >> humanMeshDiretion;
		}
		else if(type == "human_seg_out_path"){
			configIn >> humanSegOutPath;
		}
		else if(type == "cloth_seg_out_path"){
			configIn >> clothSegOutPath;
		}
		else if(type == "gravity"){
			configIn >> gravity;
		}
		else if(type == "mass"){
			configIn >> mass;
		}
		else if(type == "struct_spring_ks"){
			configIn >> struct_spring_ks;
		}
		else if(type == "struct_spring_kd"){
			configIn >> struct_spring_kd;
		}
		else if(type == "damping_force"){
			configIn >> damping_force;
		}
		else if(type == "bend_spring_ks"){
			configIn >> bend_spring_ks;
		}
		else if(type == "bend_spring_kd"){
			configIn >> bend_spring_kd;
		}
		else if(type == "step"){
			configIn >> step;
		}
		else if(type == "simulateLen"){
			configIn >> simulateLen;
		}
	}
}

Config_ Config::getInstance()
{
	if(mInstance == nullptr){
		mInstance = std::shared_ptr<Config>(new Config());
		mInstance->init("E:\\Project\\LightDrape\\data\\config");
		//mInstance->init("D:\\Develop\\project\\LightDrape\\C++\\data\\config");
	}
	return mInstance;
}
