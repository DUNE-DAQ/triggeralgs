# ChannelTimeAdjacency Algorithm

The ChannelTimeAdjacency algorithm is an enhanced version of the adjacency algorithm implemented for the HorizontalMuon algorithm, specifically focusing on the TA maker part.

## Overview

The algorithm constructs Trigger Activities (TAs) by analyzing Trigger Primitives (TPs) within a given time window. TAs are formed by grouping TPs that represent an activity or track, excluding background/outliers. The longest track is stored in the time window.

## Key Features

- Improved version of the adjacency logic present at the HorizontalMuon algorithm.
- Constructs TAs based on TPs within a TP window that have a channel-time correlation.
- Excludes background/outliers from TAs.

## References

- [Adjacency trigger refinement by Hamza Amar Es-sghir (IFIC-Valencia, Spain)](https://indico.fnal.gov/event/64229/)