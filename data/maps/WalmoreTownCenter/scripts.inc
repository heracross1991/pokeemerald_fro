WalmoreTownCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WalmoreTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

WalmoreTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_WALMORE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
WalmoreTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

WalmoreTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox WalmoreTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

WalmoreTown_PokemonCenter_1F_EventScript_Boy::
	msgbox WalmoreTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

WalmoreTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, WalmoreTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox WalmoreTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

WalmoreTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox WalmoreTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end
	
GivemonTest::
lock
msgbox T_TakeThesePokes, MSGBOX_NPC
giveitem ITEM_RARE_CANDY, 99
givemon SPECIES_STARAPTOR, 39, ITEM_NONE
release
end

WalmoreTown_PokemonCenter_1F_Text_TrainersCanUsePC: @ 81FC059
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

WalmoreTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 81FC0CD
	.string "Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

WalmoreTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 81FC148
	.string "I wonder what is happening on Jagow \nWay.$"
	

WalmoreTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 81FC1B9
	.string "Jagow Way looks clear now. I would \ntake some Antidotes if I was going \linto Jagow Woods. \pIt's crawling with Bug Pokémon.$"
	
T_TakeThesePokes:
	.string "Here take these.$"
