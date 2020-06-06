WalmoreTownCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WalmoreTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

WalmoreTown_PokemonCenter_1F_OnTransition: @ 81FC011
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

WalmoreTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FC028
	msgbox WalmoreTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

WalmoreTown_PokemonCenter_1F_EventScript_Boy:: @ 81FC031
	msgbox WalmoreTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

WalmoreTown_PokemonCenter_1F_EventScript_Girl:: @ 81FC03A
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, WalmoreTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox WalmoreTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

WalmoreTown_PokemonCenter_1F_EventScript_WirelessClubAvailable:: @ 81FC04F
	msgbox WalmoreTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end
	
GivemonTest::
lock
msgbox T_TakeThesePokes, MSGBOX_NPC
givemon SPECIES_SNIVY, 5, ITEM_NONE
givemon SPECIES_SERVINE, 5, ITEM_NONE
givemon SPECIES_SERPERIOR, 5, ITEM_NONE
givemon SPECIES_CHIMCHAR, 5, ITEM_NONE
givemon SPECIES_MONFERNO, 5, ITEM_NONE
givemon SPECIES_INFERNAPE, 5, ITEM_NONE
givemon SPECIES_MUDKIP, 5, ITEM_NONE
givemon SPECIES_MARSHTOMP, 5, ITEM_NONE
givemon SPECIES_SWAMPERT, 5, ITEM_NONE
givemon SPECIES_WURMPLE, 5, ITEM_NONE
givemon SPECIES_SILCOON, 5, ITEM_NONE
givemon SPECIES_BEAUTIFLY, 5, ITEM_NONE
givemon SPECIES_CASCOON, 5, ITEM_NONE
givemon SPECIES_DUSTOX, 5, ITEM_NONE
givemon SPECIES_WEEDLE, 5, ITEM_NONE
givemon SPECIES_KAKUNA, 5, ITEM_NONE
givemon SPECIES_BEEDRILL, 5, ITEM_NONE
givemon SPECIES_STARLY, 5, ITEM_NONE
givemon SPECIES_STARAVIA, 5, ITEM_NONE
givemon SPECIES_STARAPTOR, 5, ITEM_NONE
givemon SPECIES_BUNNELBY, 5, ITEM_NONE
givemon SPECIES_DIGGERSBY, 5, ITEM_NONE
givemon SPECIES_NATU, 5, ITEM_NONE
givemon SPECIES_XATU, 5, ITEM_NONE
givemon SPECIES_SKORUPI, 5, ITEM_NONE
givemon SPECIES_DRAPION, 5, ITEM_NONE
givemon SPECIES_PIKACHU, 5, ITEM_NONE
givemon SPECIES_RAICHU, 5, ITEM_NONE
givemon SPECIES_HIPPOPOTAS, 5, ITEM_NONE
givemon SPECIES_HIPPOWDON, 5, ITEM_NONE
givemon SPECIES_SABLEYE, 5, ITEM_NONE
givemon SPECIES_NIDORAN_M, 5, ITEM_NONE
givemon SPECIES_NIDORINO, 5, ITEM_NONE
givemon SPECIES_NIDOKING, 5, ITEM_NONE
givemon SPECIES_CLEFAIRY, 5, ITEM_NONE
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
