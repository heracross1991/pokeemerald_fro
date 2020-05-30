WalmoreTownMart_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WalmoreTown_Mart_OnFrame
	.byte 0
	
	WalmoreTown_Mart_OnFrame:
	map_script_2 VAR_WALMORE_TOWN_STATE, 0, Script_WalmoreTownMart_TilyousPackage
	.2byte 0
	
Script_WalmoreTownMart_TilyousPackage:
	lock
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox T_WalmoreTown_HeyYoureFromLakeMeadVillage, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, M_WalkToCashier
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox T_WalmoreTown_TakeTilyousParcel, MSGBOX_DEFAULT
	giveitem ITEM_TILYOUS_PARCEL, 1
	setvar VAR_WALMORE_TOWN_STATE, 1
	release
	end
	
//Movements

M_WalkToCashier:
walk_up
walk_up
walk_up
walk_up
face_left
step_end

//Text

T_WalmoreTown_HeyYoureFromLakeMeadVillage:
	.string "Cashier: Hey!\pYou're Fro, from Lake Mead \nVillage right?\p"
	.string "Fro: Hell yeah!\p"
	.string "Cashier: Can you come here I have \na favor to ask you?$"
	
T_WalmoreTown_TakeTilyousParcel:
	.string "I recieved this parcel addressed to \nProf. Tilyou. \pAmazon acidentally delivered it \nhere, is there any chance you could \ltake this back to the Professor for \lme?\p"
	.string "Fro: Sure no problem, I don't have \nanything better to do.\p"
	.string "Cashier: Gee thanks, you're a life \nsaver!$"