public class Agent
{
    public Vector3 Position { get; set; }
    public Vector3 Velocity { get; set; }

    public void Update(List<Agent> agents)
    {
        // Calculate the separation force.
        Vector3 separationForce = Vector3.zero;
        foreach (Agent agent in agents)
        {
            if (agent != this)
            {
                Vector3 direction = agent.Position - Position;
                float distance = direction.magnitude;
                separationForce += direction / (distance * distance);
            }
        }

        // Calculate the cohesion force.
        Vector3 cohesionForce = Vector3.zero;
        foreach (Agent agent in agents)
        {
            if (agent != this)
            {
                cohesionForce += agent.Position;
            }
        }
        cohesionForce /= agents.Count - 1;
        cohesionForce -= Position;

        // Calculate the alignment force.
        Vector3 alignmentForce = Vector3.zero;
        foreach (Agent agent in agents)
        {
            if (agent != this)
            {
                alignmentForce += agent.Velocity;
            }
        }
        alignmentForce /= agents.Count - 1;

        // Apply the forces to the agent's velocity.
        Velocity += separationForce * 0.1f;
        Velocity += cohesionForce * 0.05f;
        Velocity += alignmentForce * 0.05f;

        // Move the agent.
        Position += Velocity * Time.deltaTime;
    }
}
