# GoapResearch

## What is GOAP?
GOAP stands for Goal-Oriented Action Planning. It's a technique used in computer programming to make intelligent agents or characters make decisions and carry out actions to achieve specific goals.

Imagine you are playing a video game where a character needs to complete a quest. Instead of just following a predetermined script, GOAP allows the character to figure out the best sequence of actions on its own to accomplish the quest. It works like this:

**_Goals:_** The character has a list of goals or things it wants to achieve. For example, collecting items, reaching a location, or defeating enemies.

**_Actions_:** The character also knows a bunch of actions it can take, like walking, picking up items, attacking, and so on.

**_Planning:_** The character uses a clever planning process to figure out which actions to take in what order to achieve its goals. It thinks ahead, anticipating how each action affects the situation and whether it brings it closer to the goals.

**_Adaptation:_** If something changes, like an unexpected obstacle or new information, the character can adjust its plan and actions to stay on track towards the goals.

## Example:
Imagine we have an agent named Lumberjack, and the Lumberjack's job is to build shelters. The Lumberjack has a specific goal, which is to `BuildShelter`. To achieve this goal, the Lumberjack has a set of actions: `ChopLogs`, `GetAxe`, and `CollectBranches`.

The `ChopLogs` action allows the Lumberjack to obtain logs needed for building a shelter. The `GetAxe` action equips the Lumberjack with an axe, which is essential for efficiently chopping logs. On the other hand, the `CollectBranches` action also enables the Lumberjack to construct a shelter, but this method results in a smaller, lower-quality shelter. Notably, `CollectBranches` doesn't require the Lumberjack to possess an axe.

Given the `BuildShelter` goal, two distinct action plans can be formulated:

#### Plan A:
- Execute `GetAxe` action to obtain an axe.
- Use the axe to execute the `ChopLogs` action and collect logs.
- Build a shelter using the acquired logs.

#### Plan B:
- Execute the `CollectBranches` action to gather branches.
- Build a shelter using the gathered branches. This shelter may not be as substantial or well-constructed as the one from Plan A, as it lacks the quality provided by chopped logs.

Both Plan A and Plan B effectively achieve the desired goal of `BuildShelter`. If the Lumberjack successfully acquires an axe, it can efficiently obtain logs and create a sturdy shelter. However, in the absence of an axe, the Lumberjack resorts to collecting branches for a less substantial shelter.

## Why GOAP?
GOAP is a strong choice when you need characters to think ahead, adapt to surprises, and make decisions in changing scenarios. It's like giving characters a smart, problem-solving brain that can handle complex situations. While FSM (Finite State Machine) and BT (BehaviorTree) are great for simpler tasks. GOAP steps in when you want more sophisticated decision-making in your game or simulation.

## Own Implementation:
![OwnImplemantation](https://github.com/NickAzarafroz/GoapResearch/blob/master/GoapPoppy.gif)
![OwnImplemantation](https://github.com/NickAzarafroz/GoapResearch/blob/master/GoapPoppy.PNG)

In my implemantation the character's task is to build a fire pit. The character has a goal called `FirePitGoal`. To achieve this goal, the character has access to a set of actions: `GetSticks`, `GetAxe`, `ChopTree`, and `BuildFirePit`.

There are two ways the character can build the fire pit:

#### Method 1: The character can choose to follow this sequence:
- Execute the `GetAxe` action to acquire an axe.
- Use the axe to perform the `ChopTree` action and obtain wood.
- Finally, build the fire pit using the acquired wood through the `BuildFirePit` action.

#### Method 2: Alternatively, the character can opt for a different approach:
- Execute the `GetSticks` action to collect sticks.
- Directly build the fire pit using the collected sticks via the `BuildFirePit` action.

It's important to note that the second method results in a less robust fire pit compared to the first method. This is because the character didn't follow the full process of chopping a tree to obtain substantial wood.

In this scenario, the character's decision-making is guided by the goal of building a fire pit. The character can choose between the faster but weaker method or the more thorough approach for a stronger result. This showcases how the character can adapt its actions based on the available options to fulfill its goals,

## Links
#### Goal Oriented Action Planning
-- GOAP - https://gamedevelopment.tutsplus.com/tutorials/goal-oriented-action-planning-for-a-smarter-ai--cms-20793

-- GOAP - https://www.youtube.com/watch?v=LhnlNKWh7oc

