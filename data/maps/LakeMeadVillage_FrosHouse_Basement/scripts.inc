LakeMeadVillage_FrosHouse_Basement_MapScripts::
	.byte 0


LakeMeadVillage_FrosHouse_Basement_WouldYouLikeToSleep::
	lock
	msgbox Text_LakeMeadVillageFrosHouseBasement_WouldYouLikeToSleep, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LakeMeadVillage_FrosHouse_Basement_NoToSleep
	applymovement OBJ_EVENT_ID_PLAYER, MovementLakeMeadVillageFrosHouseBasementFroSleeps
	fadescreen 1
	msgbox Text_LakeMeadVillageFrosHouseBasement_YesToSleep, MSGBOX_DEFAULT
	playfanfare MUS_RG_TITLEROG
	waitfanfare
	fadescreen 0
	msgbox Text_LakeMeadVillageFrosHouseBasement_OneYearLater, MSGBOX_DEFAULT
	setvar VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 3
	setrespawn HEAL_LOCATION_LAKE_MEAD_VILLAGE
	release
	end
	
LakeMeadVillage_FrosHouse_Basement_BookOnDesk::
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Book1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Book2
	end

LakeMeadVillage_FrosHouse_Basement_PosterOnWall::
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Poster1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Poster2
	end
	
LakeMeadVillage_FrosHouse_Basement_Gamecube::
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Gamecube1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Gamecube2
	end
	
LakeMeadVillage_FrosHouse_Basement_TV::
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_TV1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_TV2
	end

LakeMeadVillage_FrosHouse_Basement_Dresser::
	compare VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 3
	goto_if_le Script_LakeMeadVillageFrosHouseBasement_Dresser1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Dresser2
	end
	
Script_LakeMeadVillageFrosHouseBasement_Dresser1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Dresser1, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_Dresser2:
	setvar VAR_LAKE_MEAD_VILLAGE_INTRO_STATE, 6
	msgbox Text_LakeMeadVillageFrosHouseBasement_Dresser2, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Gamecube1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Gamecube1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Gamecube2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Gamecube2, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_TV1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_TV1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_TV2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_TV2, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Poster1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Poster1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Poster2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Poster2, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_Book1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Book1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Book2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Book2, MSGBOX_SIGN
	end

MovementLakeMeadVillageFrosHouseBasementFroSleeps:
	face_down
	step_end
	
LakeMeadVillage_FrosHouse_Basement_NoToSleep::
	release
	end

Text_LakeMeadVillageFrosHouseBasement_WouldYouLikeToSleep:
	.string "Would you like to sleep?$"
	
Text_LakeMeadVillageFrosHouseBasement_YesToSleep:
	.string "{PLAYER} drifted off to sleep...\p"
	.string "...$"
	
Text_LakeMeadVillageFrosHouseBasement_OneYearLater:
	.string "             One Year Later...        $"
	
Text_LakeMeadVillageFrosHouseBasement_Book1:
	.string "Critique of Practical Reason by \nImmanuel Kant lays open on the desk$"
	
Text_LakeMeadVillageFrosHouseBasement_Book2:
	.string "Pokémon for Dummies lays open on \nthe desk$"
	
Text_LakeMeadVillageFrosHouseBasement_Poster1:
	.string "A Poster that reads\n“Don't Tread on Me”.\pIt has a picture of a snake on it.$"
	
Text_LakeMeadVillageFrosHouseBasement_Poster2:
	.string "A Poster that reads\n“Don't Tread on Me”.\pIt has a picture of Ekans on it.$"
	
Text_LakeMeadVillageFrosHouseBasement_Gamecube1:
	.string "A Gamecube with Smash Bro's Melee \nin it.\p"
	.string "Better not play, you're grounded.$"
	
Text_LakeMeadVillageFrosHouseBasement_Gamecube2:
	.string "You're finally allowed to play.\p"
	.string "Better not though, you're really \nfar behind your friends on your \lPokémon training. \pBetter get to it.$"
	
Text_LakeMeadVillageFrosHouseBasement_TV1:
	.string "Breaking Bad is playing on the TV.\p"
	.string "Better not watch, you're grounded.$"
	
Text_LakeMeadVillageFrosHouseBasement_TV2:
	.string "Detective Pikachu is playing on TV.\p"
	.string "You should get going.$"
	
Text_LakeMeadVillageFrosHouseBasement_Dresser1:
	.string "The top drawer of your dresser is \nfilled with socks.\p"
	.string "Most of them are full of holes.\p"
	.string "Your bottom drawer contains all of \nyour Yu-Gi-Oh cards.$"
	
Text_LakeMeadVillageFrosHouseBasement_Dresser2:
	.string "Some of your Yu-Gi-Oh cards are \nmissing...$"

	
