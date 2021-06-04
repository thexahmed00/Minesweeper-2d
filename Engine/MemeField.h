#pragma once

#include "Graphics.h"
#include "Sound.h"

class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpawnMeme();
		bool HasMeme() const;
		void Draw( const Vei2& screenPos,bool fucked,Graphics& gfx ) const;
		void Reveal();
		bool IsRevealed() const;
		void ToggleFlag();
		bool IsFlagged() const;
		bool hasNumber();
		void SetNeighborMemeCount( int memeCount );
	private:
		State state = State::Hidden;
		bool hasMeme = false;
		bool hasnumber = false;
		int nNeighborMemes = -1;
	};
public:
	MemeField( int nMemes,Vei2& center );
	void Draw( Graphics& gfx ) const;
	RectI GetRect() const;
	void OnRevealClick( const Vei2& screenPos );
	void OnFlagClick( const Vei2& screenPos );
	bool isWin();
	
private:
	Tile& TileAt( const Vei2& gridPos );
	const Tile& TileAt( const Vei2& gridPos ) const;
	Vei2 ScreenToGrid( const Vei2& screenPos );
	int CountNeighborMemes( const Vei2& gridPos );
private:
	Vei2 Topleft;
	static constexpr int width = 10;
	static constexpr int height = 6;
	bool is_Win = false;
	bool isFucked = false;
	Tile field[width * height];
	Sound sound_ = Sound(L"spayed.wav");
};