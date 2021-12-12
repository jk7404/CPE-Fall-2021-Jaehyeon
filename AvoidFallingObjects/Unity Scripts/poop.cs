using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class poop : MonoBehaviour
{
    [SerializeField]

    private Animator animator;
    // Start is called before the first frame update

    private Rigidbody2D rigidbody;  

    void Start()
    {
        animator = GetComponent<Animator>();
        rigidbody = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Ground") //Check whether the collided object's tag name is Ground
        {
            GameManager.Instance.Score(); // If the User avoid poop = a poop collides with the ground, gain 1 point 

            Destroy(this.gameObject);
            //animator.SetTrigger("poop");
        }

        if (collision.gameObject.tag == "Player") //Check whether the collided object's tag name is Player
        {
            GameManager.Instance.GameOver(); // Collision between player and poop = end

  
            Destroy(this.gameObject);
       
        }
    }


}
