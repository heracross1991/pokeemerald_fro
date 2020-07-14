LakeMeadVillage_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LakeMeadVillage_OnLoad
	//map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeMeadVillage_OnFrame
	.byte 0

//Variables
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 0 = Intro state which triggers intro event when warping to starting map. sets var to 1 after initial cutscene
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 1 = In this state the player must speak to angelina to trigger event which allows player to enter the basement. sets var to 2 when complete
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 2 = In this state the player must go to their room and go to sleep, ending the prolouge event and setting the var to 3
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 3 = Player must enter Isiahs house; when set to 3 isiahs mom event will trigger promting you to return home and setting var to 4
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 4 = Upon returning home mom event occurs; sets VAR_LAKE_MEAD_VILLAGE_INTRO_STATE to 5 and VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 1, allowing professor give pokemon event to trigger
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 5 =  as of now this serves as the final variable currently coded no special events (except 6 which offers one special dialouge option)
// VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 6 = Unlocks special dialouge option for Isiah in village


// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 0 = Default Town State, prevents player from leaving town before finding professor and picking pokemon
// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 1 = Mom has told you Isiah was just here looking for you. Now you can try to leave town and professor will stop you and take you to his lab
// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 2 = Set after professor takes you to his lab. 
// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 3 = Set after dialouge telling you to pick pokemon inside lab. also prevents player from leaving lab without picking pokemon
// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 4 = set after you pick pokemon. You can now leave the lab. Triggers battle with john when leaving Lake mead village going to Jagow Way for the first time
// VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 5 = set after battle with john. Final state as of now.


// VAR_WALMORE_TOWN_STATE 1 = this will be set to 1 in walmore town by visiting the pokemart. When set to 1 professor will give pokedex then set VAR_WALMORE_TOWN_STATE to 2.
// VAR_WALMORE_TOWN_STATE 2 = Set to this after recieved pokedex. Final state as of right now.



//Mapscripts



LakeMeadVillage_OnLoad:
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_MoveLittleBoyRemoveIsiah
	end
	

Script_LakeMeadVillage_MoveLittleBoyRemoveIsiah:
	setobjectxyperm 1, 19, 10
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
	end

//Scripts

Script_LakeMeadVillage_KidStopsYouFromLeaving::
	lock
	applymovement 1, M_KidStopsYou
	waitmovement 1
	playSE SE_PIN
	waitse
	msgbox T_KidStopsYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_FroStoppedByKid
	applymovement 1, M_KidFaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end


Script_LakeMeadVillage_TilyouStopsYouFromLeaving1::
	lock
	playSE MUS_RG_OHKIDO
	msgbox T_TilyouHeyWait, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerStopsAndTurns
	playSE SE_PIN
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 2
	applymovement 2, M_TilyouStopsPlayer1
	waitmovement 2
	msgbox T_TilyouTakesYouToLab, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyouWalksToLab1
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerWalksToLab1
	waitmovement OBJ_EVENT_ID_PLAYER
	opendoor 15 16
	waitdooranim
	applymovement 2, M_TilyouEntersLab
	waitmovement 2
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerEntersLab
	waitmovement OBJ_EVENT_ID_PLAYER
	closedoor 15 16
	waitdooranim
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2
	warp MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 0, 6, 12
	waitstate
	release
	end
	
Script_LakeMeadVillage_TilyouStopsYouFromLeaving2::
	lock
	playSE MUS_RG_OHKIDO
	msgbox T_TilyouHeyWait, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerStopsAndTurns
	playSE SE_PIN
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 2
	applymovement 2, M_TilyouStopsPlayer2
	waitmovement 2
	msgbox T_TilyouTakesYouToLab, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyouWalksToLab2
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerWalksToLab2
	waitmovement OBJ_EVENT_ID_PLAYER
	opendoor 15 16
	waitdooranim
	applymovement 2, M_TilyouEntersLab
	waitmovement 2
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerEntersLab
	waitmovement OBJ_EVENT_ID_PLAYER
	closedoor 15 16
	waitdooranim
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2
	warp MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 0, 6, 12
	waitstate
	release
	end
	

//NPCs
Script_LakeMeadVillage_NPC_LittleBoy::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_NPC_LittleBoyTilyouDialouge
	goto_if_gt Script_LakeMeadVillage_NPC_LittleBoyStandardDialouge
	release
	end
	
Script_LakeMeadVillage_NPC_LittleBoyTilyouDialouge:
	msgbox T_KidStopsYou, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_LittleBoyStandardDialouge:
	msgbox T_NPC_LittleBoyDialouge, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Boy1::
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_NPC_Boy1Dialouge1
	goto_if_gt Script_LakeMeadVillage_NPC_Boy1Dialouge2
	end
	
Script_LakeMeadVillage_NPC_Boy1Dialouge1:
	msgbox T_NPC_Boy1_BeforeRecievedPokemon, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Boy1Dialouge2:
	msgbox T_NPC_Boy1_AfterRecievedPokemon, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Isiah::
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2
	goto_if_lt Script_LakeMeadVillage_NPC_IsiahBeforeRecievedPoke
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahAfterRecievedPoke
	end
	
Script_LakeMeadVillage_NPC_IsiahBeforeRecievedPoke:
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 6
	goto_if_ge Script_LakeMeadVillage_IsiahBeforeRecievedPokeDesserChecked
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotion1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOut, MSGBOX_NPC
	end
	
	
Script_LakeMeadVillage_IsiahBeforeRecievedPokeDesserChecked:
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutDresserChecked, MSGBOX_NPC
	end
	

Script_LakeMeadVillage_NPC_IsiahTakePotion1:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutTakePotion, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked1:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutTakePotionDresserchecked, MSGBOX_NPC
	end


Script_LakeMeadVillage_NPC_IsiahAfterRecievedPoke:
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 6
	goto_if_ge Script_LakeMeadVillage_IsiahAfterRecievedPokeDesserChecked
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotion2
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThem, MSGBOX_NPC
	end

Script_LakeMeadVillage_IsiahAfterRecievedPokeDesserChecked:
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked2
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemDresserChecked, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_IsiahTakePotion2:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemTakePotion, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked2:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemTakePotionDresserChecked, MSGBOX_NPC
	end
	
//Movements

M_KidFaceLeft:
face_left
step_end

M_FroStoppedByKid:
walk_left
step_end

M_KidStopsYou:
emote_exclamation_mark
face_up
step_end

M_PlayerStopsAndTurns:
emote_question_mark
face_left
step_end

M_TilyouStopsPlayer1:
walk_up
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_TilyouWalksToLab1:
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
walk_left
face_up
step_end

M_PlayerWalksToLab1:
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
step_end

M_TilyouStopsPlayer2:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_TilyouWalksToLab2:
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
walk_left
face_up
step_end

M_PlayerWalksToLab2:
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
step_end

M_TilyouEntersLab:
walk_up
step_end

M_PlayerEntersLab:
walk_left
walk_up
step_end
	
//Signposts

Script_LakeMeadVillage_FerlitoHouseholdSign::
msgbox Text_LakeMeadVillage_FerlitoHouseholdSign, MSGBOX_SIGN
end

Script_LakeMeadVillage_TilyouLabSign::
msgbox Text_LakeMeadVillage_TilyouLabSign, MSGBOX_SIGN
end

Script_LakeMeadVillage_NallsResidenceSign::
msgbox Text_LakeMeadVillage_NallsResidenceSign, MSGBOX_SIGN
end

//Text


Text_LakeMeadVillage_TilyouLabSign:
	.string "Professor Tilyou's Lab$"
	
Text_LakeMeadVillage_FerlitoHouseholdSign:
	.string "Ferlito Household$"
	
Text_LakeMeadVillage_NallsResidenceSign:
	.string "Nalls Residence$"
	
T_KidStopsYou:
	.string "Hey!\p"
	.string "Professor Tilyou is looking for \nyou.$"
	
T_NPC_LittleBoyDialouge:
	.string "I want to grow up to be the Pokémon \nChampion. \pToo bad I can't have a Pokémon \nuntil I turn 10.$" 
	
	
T_NPC_Boy1_BeforeRecievedPokemon:
	.string "Professor Tilyou has been leading \nthe field in PokéResearch. \pI'm so glad he moved here for his \nstudies. \pHe has really helped all the \naspiring young trainers get ready \lfor their jouneys.$"

T_NPC_Boy1_AfterRecievedPokemon: 
	.string "It's amazing how fast the world has \nadapated to Pokémon. \pWe use them for all kinds of \nthings now like travel, law \lenforcement, and even nursing!$"
	
T_LakeMeadVillage_Isiah_ProfIsOut:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \ldoing field research and to look \lfor him on Jagow Way.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutTakePotion:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \llook for him on Jagow Way.\p"
	.string "Isiah stole a potion from your bag.$"

T_LakeMeadVillage_Isiah_HaventSeenThem:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.$"
	
T_LakeMeadVillage_Isiah_HaventSeenThemTakePotion:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "Isiah stole a potion from your bag.$"
	
T_TilyouHeyWait:
	.string "Hey! Wait don't go out there!$"
	
T_TilyouTakesYouToLab:
	.string "Prof. Tilyou: You can't just go \nbee-bopping all over the place \lwithout a Pokemon.\p"
	.string "You could seriously hurt yourself.\p"
	.string "Since Pokemon were discovered \nyou're not prepared to travel in \lthe wild like you used to.\p"
	.string "Why don't you come to my lab?\n"
	.string "I have some Pokemon \lto give to aspiring trainers.\p"
	.string "Bobby and John are waiting for you \nthere so you can start your \ljourneys together.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutTakePotionDresserchecked:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \llook for him on Jagow Way.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.\p" 
	.string "Isiah stole a potion from your bag.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutDresserChecked:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \llook for him on Jagow Way.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.$" 
	
T_LakeMeadVillage_Isiah_HaventSeenThemDresserChecked:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.$" 
	
T_LakeMeadVillage_Isiah_HaventSeenThemTakePotionDresserChecked:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.\p" 
	.string "Isiah stole a potion from your bag.$"
	