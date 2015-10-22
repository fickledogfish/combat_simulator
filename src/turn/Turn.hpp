namespace turn {

    enum CurrentTurn {
        DRAGON,
        ELF
    };

    struct Turn {
        CurrentTurn player;
        void switch_turn();
    };
}
