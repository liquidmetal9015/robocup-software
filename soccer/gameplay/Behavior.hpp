#pragma once

#include "GameplayModule.hpp"
#include <framework/SystemState.hpp>

namespace Gameplay
{
	class Behavior
	{
		public:
			Behavior(GameplayModule *gameplay);
			virtual ~Behavior();

			GameplayModule *gameplay() const
			{
				return _gameplay;
			}
			
			SystemState *state() const
			{
				return _gameplay->state();
			}

			// Called each frame when this behavior is current.
			// The default implementation does nothing.
			//
			// Returns true if this behavior needs to continue or false if it is done and may be replaced by another behavior.
			// The behavior may continue to be used after run() returns false.
			virtual bool run() = 0;

		protected:
			GameplayModule *_gameplay;

			// Convenience functions
			const Ball &ball() const
			{
				return state()->ball;
			}

			const GameState &gameState() const
			{
				return state()->gameState;
			}

			OurRobot *self(int i) const
			{
				return state()->self[i];
			}

			const OpponentRobot *opp(int i) const
			{
				return state()->opp[i];
			}
	};
	
	class SingleRobotBehavior: public Behavior
	{
		public:
			SingleRobotBehavior(GameplayModule *gameplay):
				Behavior(gameplay)
			{
				robot = 0;
			}
			
			OurRobot *robot;
	};
}
