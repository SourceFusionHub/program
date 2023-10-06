class Proposal {
  constructor(transaction) {
    this.transaction = transaction;
    this.votes = [];
  }
}

class Node {
  constructor() {
    this.ledger = [];
  }

  propose(transaction) {
    // Proposal Phase
    const proposal = new Proposal(transaction);
    broadcastProposal(proposal);
  }

  vote(proposal, accept) {
    // Voting Phase
    const vote = { node: this, accept };
    proposal.votes.push(vote);
    broadcastVote(proposal, vote);
  }

  aggregateVotes(proposal) {
    // Aggregation Phase
    const votesAccept = proposal.votes.filter((vote) => vote.accept);
    if (votesAccept.length >= (2 / 3) * totalNodes) {
      // Supermajority agrees
      this.addToLedger(proposal.transaction);
      broadcastConfirmation(proposal);
    }
  }

  addToLedger(transaction) {
    // Add transaction to the ledger
    this.ledger.push(transaction);
  }
}

function broadcastProposal(proposal) {
  // Broadcast the proposal to all nodes
  nodes.forEach((node) => node.vote(proposal, true));
}

function broadcastVote(proposal, vote) {
  // Broadcast the vote on the proposal to all nodes
  nodes.forEach((node) => node.aggregateVotes(proposal));
}

function broadcastConfirmation(proposal) {
  // Broadcast the confirmation to all nodes
  nodes.forEach((node) => node.addToLedger(proposal.transaction));
}

const totalNodes = 5;
const nodes = Array.from({ length: totalNodes }, () => new Node());

// Example usage:
const proposal = "Transfer $100 from A to B";
nodes[0].propose(proposal);
nodes[1].vote(nodes[0].proposal, true);
nodes[2].vote(nodes[0].proposal, true);
nodes[0].aggregateVotes(nodes[0].proposal);

console.log(nodes[0].ledger); // Check the ledger of node 0
