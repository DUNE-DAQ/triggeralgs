The ChannelAdjacency algorithm is a refined version of the HorizontalMuon algorithm (only the TA maker part for the moment). TA logic changes: in a given TP window (of default 8000 ticks), when TAs are constructed, they only contain the TPs which form an activity/track (and are not the outliers). More than one TAs per window are allowed but they should not be overlapping!

More details can be found here https://indico.fnal.gov/event/63863/ (Horizontal Muon refinement by SS Chhibra)