% Input predicates are : "initCellHasBlock(I,J,B)" (the cells containing blocks)
%                        "goalPlatform(P)" (the “goal platform, ” i.e., the platform where all blocks would end up all stacked in order)

% set maximumc number of steps to no more than 20
time(0.. n).

% six  blocks
blocks(1..6).

% 7 X 4-cells. Here, cells are encoded by pairs of numbers of the form "(I,J)", where "I" is the level (row) and "J" the platform (column)
cells(1..7,1..4).

platforms(J) :- cells(I,J).
cellHasBlock(I,J,B,0) :- initCellHasBlock(I,J,B).





% choice to move blocks to vacant platforms
{moveBlockCell(B,1,J2,T)} :- cellHasBlock(I,J1,B,T), cellClear(1,J2,T), J1 != J2, cellClear(I+1,J1,T),
                             cells(I,J1), cells(1,J2), cells(I+1,J1), blocks(B), time(T).

% choice to move blocks to occupied platforms, i.e., on top of other blocks
{moveBlockCell(B1,I2+1,J2,T)} :- cellHasBlock(I1,J1,B1,T), cellHasBlock(I2,J2,B2,T), B1 < B2, J1 != J2, cellClear(I2+1,J2,T), cellClear(I1+1,J1,T),
                                 cells(I1,J1), cells(I2,J2), cells(I2+1,J2), cells(I1+1,J1), blocks(B1), blocks(B2), time(T).





% occupied blocks due to the "move" procedure above
cellHasBlock(I,J,B,T+1) :- moveBlockCell(B,I,J,T), blocks(B), cells(I,J), time(T), time(T+1).

% occupied blocks due to "intertia," i.e., blocks that are not moved in time T stays at the same place at time T+1!
cellHasBlock(I,J,B1,T+1) :- cellHasBlock(I,J,B1,T), movedBlock(B2,T), B1!=B2, cells(I,J), time(T), time(T+1), blocks(B1), blocks(B2).

% occupied blocks after or equal to the "all stacked time" (i.e., the actual planning completion time),
% stays in the same place for the rest of the remaining bound on time
cellHasBlock(I,J,B,T1+1) :- cellHasBlock(I,J,B,T1), allStackedTime(T2), T2 <= T1, cells(I,J), time(T1), time(T1+1), time(T2), blocks(B).





% projections of the "moveBlockCell" components
movedBlock(B,T) :- moveBlockCell(B,I,J,T), blocks(B), cells(I,J), time(T).
movedTime(T) :- movedBlock(B,T), blocks(B), time(T).





% derive the unclear cells (I,J) at time T (i.e., "notCellClear(I,J,T)")
notCellClear(I,J,T) :- cellHasBlock(I,J,B,T), cells(I,J), blocks(B), time(T).

% the cleared cells are inferred by cells not having an explicit "notCellClear(I,J,T)."
cellClear(I,J,T) :- cells(I,J), time(T), not notCellClear(I,J,T).



% derive both the platform and time when they are all "stacked"
allStackedPlatformTime(P4,T) :- cellClear(1,P1,T), cellClear(1,P2,T), cellClear(1,P3,T),
                                P1 != P2, P1 != P3, P1 != P4, P2 != P3, P2 != P4, P3 != P4,
                                platforms(P1), platforms(P2), platforms(P3), platforms(P4), time(T).





% projections of the platform component of "allStackedPlatformTime"
allStackedPlatform(P) :- allStackedPlatformTime(P,T), platforms(P), time(T).

% projection of the time component of "allStackedPlatformTime" furthermore, we derive "allStackedTime(T)" as choice since we need not derive all.
% as will be seen below, we will require exactly just one "all stacked time" to hold1!
{allStackedTime(T)} :- allStackedPlatformTime(P,T), platforms(P), time(T).




% derive the (propositional) atom "hasAllStackedTime" as long as there is one "allStackedTime(T)"
hasAllStackedTime :- allStackedTime(T), time(T).




% enforce that we must have at least one "allStackedTime(T)" for some time "T"
:- not hasAllStackedTime.

% any time T2 less than the " allStackedTime(T1)" must be steps that moves blocks
:- allStackedTime(T1), T2 < T1, not movedTime(T2), time(T2).

% in contrast with the above, any time T2 more than or equal to the " allStackedTime(T1)" cannot have any more steps moving blocks
% we note that as a consequence, "allStackedTime(T1)" corresponds to the actual number of steps needed to sort and stack all the blocks in the chosen platform
:- allStackedTime(T1), T1 <= T2, movedTime(T2).

% only one block can be moved at any step
:- movedBlock(B1,T), movedBlock(B2,T), B1!=B2.

% any block cannot be in more than one cell at any time
:- cellHasBlock(I1,J1,B,T), cellHasBlock(I2,J2,B,T), I1 != I2.
:- cellHasBlock(I1,J1,B,T), cellHasBlock(I2,J2,B,T), J1 != J2.

% a cell cannot contain more than one block
:- cellHasBlock(I,J,B1,T), cellHasBlock(I,J,B2,T), B1 != B2.

% all the blocks must be stacked into the "goalPlatform(P)", where P is the goal platform
:- goalPlatform(P), not allStackedPlatform(P).




% this simply prjects the sequences of moves in terms of cell-to-cell blocks movement to be interpreted by the ROS Node
moveCellCell(T,I1,J1,I2,J2) :- cellHasBlock(I1,J1,B,T), moveBlockCell(B,I2,J2,T), cells(I1,J1), cells(I2,J2), blocks(B), time(T).


