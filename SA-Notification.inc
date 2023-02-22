//Notification Include V 0.1

//usage ShowNotification(playerid, type, "your text", show_time = default 3 second, HEX Circle colors);
#define     MAX_SN      10

new PlayerText: Label[MAX_PLAYERS][MAX_SN][8];

forward HideNotification(playerid, slot);

stock ShowNotification(playerid, E_NOTIFY_TYPE: type, buffer[], show_time = 3)
{
    new slotid = GetFreeSlot(playerid);
	if (slotid == -1) return ShowNotification(playerid, type, buffer, show_time);
	switch (type) 
	{
		case 0: //SUCCESS
		{
			GenerateHUD(playerid, slotid, buffer, 0x68f276FF);
			SetTimerEx("HideNotification", show_time*1000, false, "ii", playerid, slotid);
		}
		case 1://ERROR
		{
            GenerateHUD(playerid, slotid, buffer, 0xf26868FF); //
			SetTimerEx("HideNotification", show_time*1000, false, "ii", playerid, slotid);
		}
	}
	return 1;
}

stock GetFreeSlot(playerid)
{
	for(new z;z < MAX_SN; ++z)
	{
		if (Label[playerid][z][0]) continue;
		return z;
	}
    return -1;
}

public HideNotification(playerid, slot)
{
	for(new x; x < 8; ++x)
	{
		if (Label[playerid][slot][x])
		{
			PlayerTextDrawDestroy(playerid, Label[playerid][slot][x]);
			Label[playerid][slot][x] = 0;
		}
	}
    return 1;
}
stock GenerateHUD(playerid, slot, const text[], color = 0x0096FFFF)//The number of text characters should be less than 27
{
	new Float:ScreenXY[2];
	
	ScreenXY[1] = slot*15;
	Label[playerid][slot][0] = CreatePlayerTextDraw(playerid, 269.888946 - ScreenXY[0], 430.550994 - ScreenXY[1], "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][0], 99.880004, 11.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][0], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][0], 269488383);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][0], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][0], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][0], 0);

	Label[playerid][slot][1] = CreatePlayerTextDraw(playerid, 266.444641 - ScreenXY[0], 426.371093 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][1], 10.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][1], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][1], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][1], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][1], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][1], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][1], 0);

	Label[playerid][slot][2] = CreatePlayerTextDraw(playerid, 265.555664 - ScreenXY[0], 434.939941 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][2], 7.000000, 7.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][2], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][2], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][2], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][2], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][2], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][2], 0);

	Label[playerid][slot][3] = CreatePlayerTextDraw(playerid, 262.355712 - ScreenXY[0], 430.940002 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][3], 5.000000, 5.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][3], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][3], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][3], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][3], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][3], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][3], 0);

	Label[playerid][slot][4] = CreatePlayerTextDraw(playerid, 363.243164 - ScreenXY[0], 433.570983 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][4], 10.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][4], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][4], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][4], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][4], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][4], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][4], 0);

	Label[playerid][slot][5] = CreatePlayerTextDraw(playerid, 366.443115 - ScreenXY[0], 427.971069 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][5], 7.000000, 7.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][5], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][5], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][5], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][5], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][5], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][5], 0);

	Label[playerid][slot][6] = CreatePlayerTextDraw(playerid, 372.043029 - ScreenXY[0], 435.970947 - ScreenXY[1], "LD_BEAT:Chit");
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][6], 5.000000, 5.000000);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][6], 1);
	PlayerTextDrawColor(playerid, Label[playerid][slot][6], color);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][6], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][6], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][6], 4);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][6], 0);

	Label[playerid][slot][7] = CreatePlayerTextDraw(playerid, 319.422393 - ScreenXY[0], 431.506652 - ScreenXY[1], text);//text
	PlayerTextDrawLetterSize(playerid, Label[playerid][slot][7], 0.159999, 0.810000);
	PlayerTextDrawTextSize(playerid, Label[playerid][slot][7], 0.000000, -8.880001);
	PlayerTextDrawAlignment(playerid, Label[playerid][slot][7], 2);
	PlayerTextDrawColor(playerid, Label[playerid][slot][7], -1);
	PlayerTextDrawSetShadow(playerid, Label[playerid][slot][7], 0);
	PlayerTextDrawBackgroundColor(playerid, Label[playerid][slot][7], 255);
	PlayerTextDrawFont(playerid, Label[playerid][slot][7], 1);
	PlayerTextDrawSetProportional(playerid, Label[playerid][slot][7], 1);

	for(new x; x < 8; ++x)
	{
		PlayerTextDrawShow(playerid, Label[playerid][slot][x]);
	}
    return 1;
}
