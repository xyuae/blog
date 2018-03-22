# Difference between clone and clone --mirror
The difference is that when using --mirror, all refs are copied as-is. This means everything: remote-tracking branches, notes, refs/originals/* (backups from filter-branch). The cloned repo has it all. It's also set up so that a remote update will re-fetch everything from the origin (overwriting the copied refs). The idea is rally to mirror the repository, to have a total copy, so that you could for example host your central repo in multiple places, or back  it up. Think of jus tstaright-up copying the repo, except in a much more elegant git way.

The new documentation preety much says all this:

## --mirror
Set up a mirror of the source repository. This implies --bare. Compare dot --bare, --mirror not only maps local branches of the source to local branches of the target, it maps all refs (inclding remote branches, notes etc.) and sets upa refspec configuration such that all these refs are overwritten by a git emote update in the taret repository.

My original answer also noted the differences between a bare clone and a normal (non-bare) clone - the non-bare clone sets up remote tracking brances, only creating a local branch for HEAD, while the bare clone copies the brances directly.

Suppose origin has a few branches (master HEAD, next, pu , and maint), some tags( v1, v2, v3), some remote branches (devA/master, devB/master), and some other refs(refs/bfoo/bar, refs/foo/baz, which might be notes, stashes, other devs' namespaces, who knows).
- git clone original-url (non-bare): you will get all of the tags copied, a local branch master (HEAD) tracking a remote branch origin/master, and remote branches origin/next, origin/pu, and origin/maint. The tracking branches are set up so that if you do something like git fetch origin, they will be fetched as you expect. Any remote branhes (in the cloned remote) and other refs are completely ignored.

- git clone --bare origin-url: you will get all of the tags copied, local branches master, no remote tracking branches. Tha is , all branches are copied as is, and it's set up completely independnet, with no expectation of fecghing again. Any remote branches (in the cloned remote) and other refs are completely ignored.

- git clone --mirror original-url: every last one of those refs will be copied as-is. You will get all the tags, local branches, remote branches. Everything is exactly as it was in the cloned remote. remote tackingis ewt up so that if you run git remote update all refs will be overwritten from ogrin, as if you'd just deleted the mirror an recloned it. As the docs originally said, its' a mirror. it's supposed to be functionally identical copy, interchageable with the original.
