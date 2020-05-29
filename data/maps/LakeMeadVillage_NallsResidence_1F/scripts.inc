LakeMeadVillage_NallsResidence_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MS_LakeMeadVillage_NallsResidence_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MS_LakeMeadVillage_NallsResidence_1F_OnFrame
	.byte 0

MS_LakeMeadVillage_NallsResidence_1F_OnFrame:
	map_script_2 VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 3, Script_LakeMeadVillage_NallsResidence_1F_IsiahIsOut
	.2byte 0

Script_LakeMeadVillage_NallsResidence_1F_IsiahIsOut:
	lock
	applymovement 1, M_IsiahMomMovesToPlayer
	playSE SE_PIN
	waitmovement 1
	msgbox T_IsiahLookingForYou, MSGBOX_DEFAULT
	setvar VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 4
	release
	end
	
MS_LakeMeadVillage_NallsResidence_1F_OnLoad:
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 3
	goto_if_eq Script_LakeMeadVillage_NallsResidence_1F_HideIsiahMoveMom
	end
	
Script_LakeMeadVillage_NallsResidence_1F_HideIsiahMoveMom:
	removeobject 3
	setflag FLAG_HIDE_NALLS_RESIDENCE_1F_ISIAH
	setobjectxyperm 1, 2, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	end


//NPCS

Script_NallsResidence_IsiahMom_NPC::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 4
	goto_if_eq Script_NallsResidence_IsiahMom_NPCDialouge1
	goto_if_gt Script_NallsResidence_IsiahMom_NPCDialouge2
	end

Script_NallsResidence_IsiahMom_NPCDialouge1:
	msgbox T_IsiahLookingForYou, MSGBOX_NPC
	end

Script_NallsResidence_IsiahMom_NPCDialouge2:
	msgbox T_NallsResidence_ImGladYoureFriends, MSGBOX_NPC
	end

Script_NallsResidence_IsiahDad_NPC::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 4
	goto_if_eq Script_NallsResidence_IsiahDad_NPCDialouge1
	goto_if_gt Script_NallsResidence_IsiahDad_NPCDialouge2
	end

Script_NallsResidence_IsiahDad_NPCDialouge1:
	msgbox T_IsiahAlwaysOutExploring, MSGBOX_NPC
	end

Script_NallsResidence_IsiahDad_NPCDialouge2:
	msgbox T_NallsResidence_IsiahGettingIntoTrouble, MSGBOX_NPC
	end
	
M_IsiahMomMovesToPlayer:
	emote_exclamation_mark
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end
	
T_IsiahLookingForYou:
	.string "Isiah's Mom: Anthony, how good to \nsee you.\p"
	.string "Isiah just headed over to your \nhouse, you must have missed him on \lthe way here. \pHe was going to tell you Professor \nTilyou went out to do field \lresearch so you'll have to wait for \lhim to get back to get your \lPokémon.$"

T_NallsResidence_ImGladYoureFriends:
	.string "Isiah's Mom: " 
	.string "I'm glad you and Isiah \nare friends. \pYou are both such good boys!$"
	
T_IsiahAlwaysOutExploring:
	.string "Isiah's Dad: Isiah is always out \nexploring. \pI barely see him anymore since \nTrump developed the lake he spends \lmost of his free time there.$"
	
T_NallsResidence_IsiahGettingIntoTrouble:
	.string "Isiah's Dad: My son told me he \nheard a strange noise coming from \linside the caves at the center of \lLake Mead. \pI wish that boy would stay out of \ntrouble!$"