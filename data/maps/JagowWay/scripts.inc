JagowWay_MapScripts::
	.byte 0


Script_JagowWay_StarterBattle:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	applymovement 1, M_JagowWay_JohnChallengesFro
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	switch VAR_STARTER_CHOICE
	case 1, Script_JagowWay_StarterBattleSnivy
	case 2, Script_JagowWay_StarterBattleMudkip
	case 3, Script_JagowWay_StarterBattleChimchar
	end
	
Script_JagowWay_StarterBattleSnivy:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleMudkip:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleChimchar:
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end	
	
Script_JagowWay_StarterBattle2:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	applymovement 1, M_JagowWay_JohnChallengesFro2
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	switch VAR_STARTER_CHOICE
	case 1, Script_JagowWay_StarterBattleSnivy
	case 2, Script_JagowWay_StarterBattleMudkip
	case 3, Script_JagowWay_StarterBattleChimchar
	end
	
Script_JagowWay_AfterJohnBattle:
setvar VAR_LAKE_MEAD_VILLAGE_TOWN_STATE, 5
msgbox T_JohnAfterBattle
applymovement 1, M_JagowWay_JohnLeaves
waitmovement 1
removeobject 1
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
release
end


release
end


Script_JagowWay_NorthSignPost::
msgbox T_JagowWay_SignPostForLakeMead, MSGBOX_SIGN
release
end

//Movements

M_JagowWay_JohnLeaves:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_JagowWay_JohnChallengesFro:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

M_JagowWay_JohnChallengesFro2:
walk_down
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

//Text

T_JagowWay_SignPostForLakeMead:
	.string "{DOWN_ARROW} Walmore Town \n{UP_ARROW} Sy Pathway$"
	

T_JagowWay_JohnBattleDialouge:
	.string "John: Hey Fro, before you go out \ninto the wild why don't I show you \lhow to battle with your new \lPokemon?\p"
	.string "Fro: How hard can it be? Is this \nreally necessary?$"
	
T_JagowWay_JohnBattleDialouge2: 
	.string "John: Experience is a valuable \nteacher. Now let's battle!$"

T_JagowWay_JohnDefeated:
	.string "John: You're a natural, Fro!$"
	
T_JohnAfterBattle:
	.string "John: Great job Fro. I look forward \nto seeing you grow as a trainer. \pNext time I won't take it easy on \nyou.\p"
	.string "Now I'm going to head to Summit \nCity to challenge the Gym there! \pYou should too!\p"
	.string "I bet Bobby is already there. \pCan't get too far behind!$"