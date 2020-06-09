LakeMeadVillage_TilyousLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MS_LakeMeadVillage_TilyousLab_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MS_LakeMeadVillage_TilyousLab_OnFrame
	.byte 0


// Map Scripts

MS_LakeMeadVillage_TilyousLab_OnLoad::
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2
	goto_if_lt Script_TilyousLab_RemoveTilyouBobbyJohn
	goto_if_eq Script_TilyousLab_ShowTilyouBobbyJohn
	compare VAR_WALMORE_TOWN_STATE, 1
	goto_if_eq Script_TilyousLab_MoveTilyouPokedex
	end

MS_LakeMeadVillage_TilyousLab_OnFrame::
	map_script_2 VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2, Script_TilyousLab_PickAPokemon
	.2byte 0
	
//Scripts

Script_TilyousLab_MoveTilyouPokedex:
setobjectxyperm 1, 3, 2
setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
end

Script_TilyousLab_RemoveTilyouBobbyJohn:
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	end

Script_TilyousLab_ShowTilyouBobbyJohn:
	addobject 1
	addobject 2
	addobject 3
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setobjectxyperm 1, 6, 11
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	end
	
Script_TilyousLab_PickAPokemon:
	applymovement 1, M_TilyousLab_TilyouMovesToTop
	applymovement OBJ_EVENT_ID_PLAYER, M_TilyousLab_PlayerFollows
	waitmovement 1
	msgbox T_TilyousLab_TellPlayerToPick, MSGBOX_DEFAULT
	applymovement 2, M_TilyousLab_BobbyFacesTilyou
	waitmovement 2
	msgbox T_TilyousLab_BobbySaysFroCanGo MSGBOX_DEFAULT
	applymovement 3, M_TilyousLab_JohnFacesTilyou
	waitmovement 3
	msgbox T_TilyousLab_JohnAgrees MSGBOX_DEFAULT
	applymovement 2, M_TilyousLab_BobbyFacesDown
	applymovement 3, M_TilyousLab_JohnFacesDown
	waitmovement 3
	msgbox T_TilyousLab_OkAnthonyGoAhead, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 3
	release
	end
	
Script_TilyousLab_DontLeaveBeforePickingAPokemon::
	lock
	msgbox T_TilyousLab_HeyDontGoYet, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TilyousLab_PlayerCantLeave
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end

Script_TilyousLab_SnivyPokeball::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_SNIVY, 10, 3
	msgbox T_TilyousLab_PickSnivy, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_SnivyYes
	closemessage
	release
	end
	
Script_TilyousLab_SnivyYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_CHOICE 1
	givemon SPECIES_SNIVY, 5, ITEM_NONE
	playfanfare MUS_FANFA4
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SNIVY
	waitfanfare
	msgbox T_TilyousLab_SnivyYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end
	
TilyousLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto TilyousLab_BobbyAndJohnPick
	end
	
TilyousLab_BobbyAndJohnPick:
	msgbox T_TilyousLab_OkJohnYoureUp MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnFacesTilyou
	waitmovement 3
	msgbox T_TilyousLab_JohnSoundsGood, MSGBOX_DEFAULT
	closemessage
	compare VAR_STARTER_CHOICE, 1
	goto_if_eq Script_TilyousLab_FroTookSnivy
	compare VAR_STARTER_CHOICE, 2
	goto_if_eq Script_TilyousLab_FroTookMudkip
	compare VAR_STARTER_CHOICE, 3
	goto_if_eq Script_TilyousLab_FroTookChimchar
	release
	end

Script_TilyousLab_FroTookSnivy:
	applymovement 3, M_TilyousLab_JohnChimchar
	waitmovement 3
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHIMCHAR
	msgbox T_TilyousLab_JohnChimchar, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnChimcharReturn
	applymovement 2, M_TilyousLab_BobbyMudkip
	waitmovement 2
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_MUDKIP
	msgbox T_TilyousLab_BobbyMudkip
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyMudkipExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 4
	
	release
	end

Script_TilyousLab_MudkipPokeball::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox T_TilyousLab_PickMudkip, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_MudkipYes
	closemessage
	release
	end
	
	
Script_TilyousLab_MudkipYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_CHOICE 2
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	playfanfare MUS_FANFA4
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_MUDKIP
	waitfanfare
	msgbox T_TilyousLab_MudkipYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookMudkip:
	applymovement 3, M_TilyousLab_JohnSnivy
	waitmovement 3
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SNIVY
	msgbox T_TilyousLab_JohnSnivy, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnSnivyReturn
	applymovement 2, M_TilyousLab_BobbyChimchar
	waitmovement 2
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHIMCHAR
	msgbox T_TilyousLab_BobbyChimchar
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyChimcharExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 4
	release
	end	
	
Script_TilyousLab_ChimcharPokeball::
	lock
	compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_CHIMCHAR, 10, 3
	msgbox T_TilyousLab_PickChimchar, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_ChimcharYes
	closemessage
	release
	end
	
	
Script_TilyousLab_ChimcharYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_CHOICE 3
	givemon SPECIES_CHIMCHAR, 5, ITEM_NONE
	playfanfare MUS_FANFA4
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHIMCHAR
	waitfanfare
	msgbox T_TilyousLab_ChimcharYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookChimchar:
	applymovement 3, M_TilyousLab_JohnMudkip
	waitmovement 3
	removeobject 5
	msgbox T_TilyousLab_JohnMudkip, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_MUDKIP
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnMudkipReturn
	applymovement 2, M_TilyousLab_BobbySnivy
	waitmovement 2
	removeobject 4
	msgbox T_TilyousLab_BobbySnivy
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SNIVY
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbySnivyExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 4
	release
	end	


Script_TilyousLab_ProfTilyousPokeball:
	msgbox T_TilyousLab_ProfTilyousPokemon, MSGBOX_NPC
	release
	end

// Movements

M_TilyousLab_JohnMudkip:
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnMudkipReturn:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbySnivy:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_BobbySnivyExit:
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_JohnSnivy:
walk_down
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnSnivyReturn:
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbyChimchar:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_BobbyChimcharExit:
walk_down
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
step_end

M_TilyousLab_JohnExits:
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_BobbyMudkipExit:
walk_down
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_BobbyMudkip:
walk_down
walk_right
walk_right
walk_right
walk_right
walk_down
walk_right
walk_right
walk_up
step_end


M_TilyousLab_JohnChimcharReturn:
walk_down
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_up
walk_up
face_down
step_end

M_TilyousLab_JohnChimchar:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_PlayerCantLeave:
walk_up
step_end

M_TilyousLab_JohnFacesDown:
face_down
step_end

M_TilyousLab_BobbyFacesDown:
face_down
step_end

M_TilyousLab_JohnFacesTilyou:
face_right
step_end

M_TilyousLab_BobbyFacesTilyou:
face_right
step_end

M_TilyousLab_TilyouMovesToTop:
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
face_down
step_end

M_TilyousLab_PlayerFollows:
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
step_end


//NPCS

Script_TilyousLab_NPC_Tilyou::
lock
compare VAR_WALMORE_TOWN_STATE, 1
goto_if_eq Script_TilyousLab_TilyouGivesPokedex
compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 3
goto_if_eq Script_TilyousLab_GoAheadAnthony
compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE 4
goto_if_ge Script_TilyousLab_GoodLuckOnYourAdventure
release
end

Script_TilyousLab_TilyouGivesPokedex:
faceplayer
msgbox T_TilyousLab_FroGivesParcel, MSGBOX_DEFAULT
applymovement 1, Common_Movement_Delay48
waitmovement 0
playfanfare MUS_FANFA4
msgbox T_TilyousLab_RecievedPokedex
waitfanfare
msgbox T_TilyousLab_ExplainPokedex
setflag FLAG_SYS_POKEDEX_GET
removeitem ITEM_TILYOUS_PARCEL, 1
closemessage
release
end


end


Script_TilyousLab_GoAheadAnthony:
msgbox T_TilyousLab_GoAheadAnthony, MSGBOX_NPC
end

Script_TilyousLab_GoodLuckOnYourAdventure:
msgbox T_TilyousLab_GoodLuckOnYourAdventure, MSGBOX_NPC
end

Script_TilyousLab_NPC_John::
lock
msgbox T_TilyousLab_JohnLongTimeNoSee, MSGBOX_NPC
end

Script_TilyousLab_NPC_Bobby::
lock
msgbox T_TilyousLab_BobbyAllPokesAreViable, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist1::
lock
compare VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 2
goto_if_gt Script_TilyousLab_NPC_Scientist1Dialouge2
msgbox T_TilyousLab_DoesntSpendAlotOfTimeInLab, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist1Dialouge2:
msgbox T_TilyousLab_HeWontStayLong, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist2::
lock
msgbox T_TilyousLab_WonAwards, MSGBOX_NPC
end


//Text

T_TilyousLab_TellPlayerToPick:
	.string "Prof. Tilyou: As you can see there \nare three Pokéballs on the table. \pI have one for you, one for John, \nand one for Bobby. \pThey were nice enough to wait for \nyou to be ungrounded to start \ltheir journeys. \pNow it is time to choose your \nPokémon. \pWho wants to go first?$"

T_TilyousLab_BobbySaysFroCanGo:
	.string "Bobby: Let Fro go, he's been stuck \ninside his house for a year. \pPlus John and I know what were \ndoing, Fro has never even played a \lPokémon game before!$"
	
T_TilyousLab_JohnAgrees:
	.string "John: Yea, let Fro go first!$"
	
T_TilyousLab_OkAnthonyGoAhead:
	.string "Prof. Tilyou: Alright then, we are \nall in agreement. \pGo ahead Anthony, pick your \nPokémon. \pChoose carefully!$"
	
T_TilyousLab_HeyDontGoYet:
	.string "Prof. Tilyou: Hey, don't go yet!\p"
	.string "I'm trying to help you not die. I \ncould always give you a carbon \lmonoxide detector if you would \lprefer!$"
	
T_TilyousLab_ProfTilyousPokemon:
	.string "A Pokéball belonging to Prof. \nTilyou. \pYou can hear a quite buzz coming \nfrom inside of it.$"
	
T_TilyousLab_PickSnivy:
	.string "The Pokéball contains the grass \ntype Pokémon Snivy. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_SnivyYes:

	.string "You've recieved Snivy!\p"
	.string "Why don't you give it a nickname?$"

T_TilyousLab_OkJohnYoureUp:
	.string "Prof Tilyou: Great choice Anthony. \pYou're up John, go ahead and pick!$"
	
T_TilyousLab_JohnSoundsGood:
	.string "John: Sounds good! I know who I \nwant!$"
	
T_TilyousLab_JohnChimchar:
	.string "John took the Fire Pokémon, \nChimchar!\p"
	.string "John: Chimchar is so lit!$"

T_TilyousLab_TilyouBobbysTurn:
	.string "Prof. Tilyou: Great pick Johnny \nWaffles. \pNow it's time for Bobby to pick!$"
	
T_TilyousLab_BobbyMudkip:
	.string "Bobby took the Water Pokémon, \nMudkip!$"

T_TilyousLab_YouAllHaveStarters:
	.string "Prof Tilyou: Well it looks like you \nall have companions for your \ljourney. Get out there and start \ltraining your Pokémon!\p"
	.string "Bobby: Let's do it! \pGood luck boys, see you at Victory \nRoad!\p"
	.string "John: YEEEEEEEEEET!!!!$"
	
T_TilyousLab_GoAheadAnthony:
	.string "Go ahead Anthony, pick your \nPokémon. \pChoose carefully!$"
	
T_TilyousLab_GoodLuckOnYourAdventure:
	.string "Good luck on your adventure! Take \ncare of your Pokémon.$"

T_TilyousLab_BobbyAllPokesAreViable:
	.string "Bobby: I took a look at the Pokémon \navailable. They are all in the OU \lcategory on Smogon so any choice \lwill be fine.$"
	
T_TilyousLab_JohnLongTimeNoSee:
	.string "John: What's up Fro, long time no \nsee.\p"
	.string "Hurry up and pick a Pokémon. We've \nbeen waiting the whole year on you.\p"
	.string "Don't make us wait any longer!$"
	
T_TilyousLab_PickMudkip:
	.string "The Pokéball contains the water \ntype Pokémon Mudkip. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_MudkipYes:

	.string "You've recieved Mudkip!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnSnivy:
	.string "John took the Grass Pokémon, \nSnivy!\p"
	.string "John: My Snivy is on fleek!$"
	
T_TilyousLab_BobbyChimchar:
	.string "Bobby took the Fire Pokémon, \nChimchar!$"
	
T_TilyousLab_PickChimchar:
	.string "The Pokéball contains the Fire \ntype Pokémon Chimchar. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_ChimcharYes:

	.string "You've recieved Chimchar!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnMudkip:
	.string "John took the Water Pokémon, \nMudkip!\p"
	.string "John: Mudkip is dirty A F!$"
	
T_TilyousLab_BobbySnivy:
	.string "Bobby took the Grass Pokémon, \nSnivy!$"
	
T_TilyousLab_DoesntSpendAlotOfTimeInLab:
	.string "I'm not sure where Prof. Tilyou is. \nHe is not in the Lab very often. He \lprefers to do field work.\p"
	.string "Can't say I blame him.$"

T_TilyousLab_HeWontStayLong:
	.string "Prof Tilyou won't stay in the lab \nlong. \pHe will be back in the field \nleaving us to do the grunt work!$"

T_TilyousLab_WonAwards:
	.string "Prof. Tilyou has won awards for his \nworld class Pokéresearch.$"
	
T_TilyousLab_FroGivesParcel:
	.string "Fro: I was at the Pokémart in \nWalmore Town and the clerk said \lyour package was mistakenly \ldelivered to his store.\p"
	.string "Prof Tilyou: Wowie, thanks Anthony! \nI've been fighting with amazon \labout this for quite a while. \pThey were insistant that it was \ndelivered to me. I had just about \lgiven up and was about to order \lanother with free two day shipping!\p"
	.string "Anyway, this is the Pokédex I have \nbeen waiting for to help with my \lresearch. \pAlthough, I've been so busy lately\n"
	.string "I don't know how often I can use \lit. I have an idea,"
	.string "why don't you \ltake the Pokédex and help me with \lmy research while you travel?$"
	
T_TilyousLab_RecievedPokedex:
	.string "You recieved the Pokédex!$"
	
T_TilyousLab_ExplainPokedex:
	.string "Prof. Tilyou: The Pokédex is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any Pokémon you meet or catch.\p"
	.string "John and Bobby go everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare Pokémon\n"
	.string "and records its data in the Pokédex,\l"
	.string "he looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"
	